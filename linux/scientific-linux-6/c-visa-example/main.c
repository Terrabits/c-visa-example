

// Include visa types, functions
#include "visa.h"

#include <stdio.h>
#include <string.h>


int main()
{
	// Status variable
	// Each VISA function returns a status code
	// indicating success or type of failure
	ViStatus status;

	// Get VISA resource manager
	ViSession resource_manager;
	status = viOpenDefaultRM(&resource_manager);
	if (status != VI_SUCCESS) {
		printf("Could not open VISA resource manager.\n");
		return 0;
	}

	// Connect to instrument
	// The resource string indicates how/where to
	// connect to the instrument.
	// The most common resource strings are:
	//   TCPIP::<address>::INSTR
	//   GPIB::<address>::INSTR
	// Access mode doesn't usually need to be changed
	// from it's default setting (null).
	ViChar resource_string[] = "TCPIP::192.168.1.107::INSTR";
	ViSession instrument;
	ViAccessMode access_mode = VI_NULL;
	ViUInt32 timeout_ms = 5000;
	status = viOpen(resource_manager, resource_string, access_mode, timeout_ms, &instrument);
	if (status != VI_SUCCESS) {
		printf("Could not connect to the instrument.\n");
		return 0;
	}

	// Write a SCPI command to the instrument
	// The "*IDN?" command requests the
	// identification string from the instrument.
	ViBuf scpi_command = "*IDN?";
	ViUInt32 length_B = (ViUInt32)strlen(scpi_command);
	ViUInt32 sent_B;
	status = viWrite(instrument, scpi_command, length_B, &sent_B);
	if (status != VI_SUCCESS) {
		printf("Could not write to instrument.\n");
		return 0;
	}

	// Read response from instrument
	// Response (identification string) should
	// look something like this
	// (depending on model):
	// "Rohde-Schwarz,ZNBT8-8Port,1318700624100104,2.70"
	const ViUInt32 buffer_size_B = 100;
	ViChar response_buffer[100];
	ViUInt32 read_B;
	status = viRead(instrument, response_buffer, buffer_size_B, &read_B);
	if (status != VI_SUCCESS) {
		printf("Could not read response from instrument.\n");
		return 0;
	}

	// Response is not null-terminated.
	// Add '\0' at end.
	if (read_B < buffer_size_B) {
		response_buffer[read_B] = '\0';
	}
	else {
		response_buffer[buffer_size_B] = '\0';
	}

	// Display response
	printf("Instrument id string:\n");
	printf(response_buffer);
	printf("\n");
	return 0;
}
