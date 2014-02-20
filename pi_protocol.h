/*
 ************************************************************
 * PiMash - 
 * 	Defines the pi-mash protocol types
 ************************************************************
 */
#ifndef __PI_PROTOCOL_H
#define __PI_PROTOCOL_H

// No byte alignment for any of the following protocol defs
#pragma pack (push,1)

// Pi Protocol type definitions
typedef unsigned char pit_byte_t;
typedef unsigned short pit_word_t;
typedef unsigned long pit_dword_t;
typedef float pit_float_t;

// PiMash protocol enumerations
typedef enum _function_code_t
    {
    pif_read,
    pif_write    
    } function_code_t;

typedef enum _status_code_t
    {
    pis_success = 1,
    pis_failure,
    } status_code_t;

typedef enum _address_type_t
    {
    pit_byte = 1,    // 1-byte unsigned int
    pit_word,        // 2-byte unsigned int
    pit_dword,       // 4-byte unsigned int
    pit_float,       // 32-bit IEEE float
    } address_type_t;

// Pi Protocol sturctures
typedef struct _pi_request_t
    {
    pit_byte_t start_of_frame;
    pit_byte_t func_and_addrtype;    
    pit_byte_t address;
    } pi_request_t;

typedef struct _pi_response_t
    {
    pit_byte_t start_of_frame;
    pit_byte_t status;
    pit_byte_t data[sizeof(pit_float_t)]; // 4-byte max
    } pi_response_t;
#pragma pack(pop)

#endif //__PI_PROTOCOL_H
