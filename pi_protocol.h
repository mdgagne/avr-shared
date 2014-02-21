/*
 ************************************************************
 * PiMash - 
 * 	Defines the pi-mash protocol enumerations and types
 *  shared between the avr-pimash and avr-connector repos
 ************************************************************
 */
#ifndef __PI_PROTOCOL_H
#define __PI_PROTOCOL_H

// No byte alignment for any of the following protocol defs
#pragma pack (push,1)

// Pi Protocol type definitionsa
typedef unsigned char pit_byte_t;
typedef unsigned short pit_word_t;
typedef unsigned long pit_dword_t;
typedef float pit_float_t;

// PiMash protocol enumerations
enum function_code_t
    {
    pif_read,
    pif_write    
    };

enum status_code_t
    {
    pis_success = 1,
    pis_failure,
    };

enum start_of_frame_t
    {
    start_request = 0x50,   // P
    start_response = 0x49,     // I
    };

enum address_type_t
    {
    pit_byte = 1,    // 1-byte unsigned int
    pit_word,        // 2-byte unsigned int
    pit_dword,       // 4-byte unsigned int
    pit_float,       // 32-bit IEEE float
    };

enum byte_address_t
    {
    pid_run,    // 1 = PID relay operate, 0 = PID relay off   
    flow_lock,  // require a non-zero flow rate to activate relay output
    };

enum word_address_t
    {
    temp_wsize,  // temp relay output window size (ms)
    temp_srate,  // temp process value sample rate

    flow_srate,  // flow process value sample rate
    };

enum dword_address_t
    {
    none, // so far
    };

enum float_address_t
    {
    temp_sp,    // temperature setpoint (C)
    temp_pv,    // temperature process value (C)
    temp_kp,    // temperature PID proportional gain
    temp_ki,    // temperature PID integral gain
    temp_kd,    // temperature PID derivative gain

    flow_pv,    // flow process value (liter/min)
    };

// Pi Protocol structures
typedef struct
    {
    pit_byte_t start_of_frame;
    pit_byte_t func_and_addrtype;    
    pit_byte_t address;
    } pi_request_t;

// The response is fixed size; the data is null-padded in the event
// the data requires less than 4 bytes
typedef struct
    {
    pit_byte_t start_of_frame;
    pit_byte_t status;
    pit_byte_t data[sizeof(pit_float_t)]; // 4-byte max
    } pi_response_t;
#pragma pack(pop)

#endif //__PI_PROTOCOL_H
