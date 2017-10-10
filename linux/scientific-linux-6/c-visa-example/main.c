

// Include visa types, functions
#include "visa.h"

#include <stdio.h>
#include <string.h>


int main()
{
	// Connection info
	ViChar resource_string[] = "TCPIP::192.168.1.107::INSTR";
	ViAccessMode access_mode = VI_NULL;
	ViUInt32 timeout_ms      = 5000;

	// Communication buffer
	const ViUInt32 buffer_size_B = 1000;
	ViChar buffer[1000];
	ViUInt32 io_bytes;

	// Get VISA resource manager
	ViSession resource_manager;
	ViStatus  status;
	status = viOpenDefaultRM(&resource_manager);
	if (status < VI_SUCCESS) {
		printf("Could not open VISA resource manager.\n");
		return 0;
	}

	// Connect to instrument
	ViSession instrument;
	status = viOpen(resource_manager, resource_string, access_mode, timeout_ms, &instrument);
	if (status < VI_SUCCESS) {
		printf("Error connecting to instrument\n");
		viStatusDesc(resource_manager, status, buffer);
		printf("%s\n", buffer);
		return 0;
	}

	// Write *IDN? (id string?)
	ViBuf scpi_command = "*IDN?";
	status = viWrite(instrument, scpi_command, (ViUInt32)strlen(scpi_command), &io_bytes);
	if (status < VI_SUCCESS) {
		printf("Error writing to instrument\n");
		viStatusDesc(resource_manager, status, buffer);
		printf("%s\n", buffer);
		return 0;
	}

	// Read response from instrument
	// Response (identification string) should
	// look something like this
	// (depending on model):
	// "Rohde-Schwarz,ZNBT8-8Port,1318700624100104,2.70"
	status = viRead(instrument, buffer, buffer_size_B, &io_bytes);
	if (status < VI_SUCCESS) {
		printf("Error reading from instrument\n");
		viStatusDesc(resource_manager, status, buffer);
		printf("%s\n", buffer);
		return 0;
	}

	// Response is not null-terminated.
	// Add '\0' at end.
	if (io_bytes < buffer_size_B) {
		buffer[io_bytes] = '\0';
	}
	else {
		buffer[buffer_size_B] = '\0';
	}

	// Display response
	printf("Instrument id string:\n%s\n\n", buffer);
	return 0;
}
