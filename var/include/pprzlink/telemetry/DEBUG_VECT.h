/** @file
 *  @brief PPRZLink message header for DEBUG_VECT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DEBUG_VECT_H_
#define _VAR_MESSAGES_telemetry_DEBUG_VECT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DEBUG_VECT 53
#define PPRZ_MSG_ID_DEBUG_VECT 53

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DEBUG_VECT _send_msg(DEBUG_VECT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DEBUG_VECT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param nb_name,_name 
 * @param nb_vector,_vector 
 */
static inline void pprzlink_msg_v2_send_DEBUG_VECT(struct pprzlink_msg * msg, uint8_t nb_name, char *_name, uint8_t nb_vector, float *_vector) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+nb_name*1+1+nb_vector*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+nb_name*1+1+nb_vector*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DEBUG_VECT, "DEBUG_VECT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_name, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_CHAR, DL_FORMAT_ARRAY, (void *) _name, nb_name*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_vector, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _vector, nb_vector*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DEBUG_VECT pprz_msg_send_DEBUG_VECT
#define DOWNLINK_SEND_DEBUG_VECT(_trans, _dev, nb_name, name, nb_vector, vector) pprz_msg_send_DEBUG_VECT(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_name, name, nb_vector, vector)
/**
 * Sends a DEBUG_VECT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param nb_name,_name 
 * @param nb_vector,_vector 
 */
static inline void pprz_msg_send_DEBUG_VECT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t nb_name, char *_name, uint8_t nb_vector, float *_vector) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DEBUG_VECT(&msg,nb_name,_name,nb_vector,_vector);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DEBUG_VECT(_trans, _dev, nb_name, name, nb_vector, vector) {}
static inline void pprz_send_msg_DEBUG_VECT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t nb_name __attribute__((unused)), char *_name __attribute__((unused)), uint8_t nb_vector __attribute__((unused)), float *_vector __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array name in message DEBUG_VECT
 *
 * @return name : 
 */
 static inline uint8_t pprzlink_get_DEBUG_VECT_name_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 4);
}

/** Getter for field name in message DEBUG_VECT
  *
  * @param _payload : a pointer to the DEBUG_VECT message
  * @return 
  */
static inline char * pprzlink_get_DL_DEBUG_VECT_name(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_char_array(_payload, 5);
}

/** Getter for length of array vector in message DEBUG_VECT
 *
 * @return vector : 
 */
 static inline uint8_t pprzlink_get_DEBUG_VECT_vector_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 5);
}

/** Getter for field vector in message DEBUG_VECT
  *
  * @param _payload : a pointer to the DEBUG_VECT message
  * @return 
  */
static inline float * pprzlink_get_DL_DEBUG_VECT_vector(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 6);
}


/* Compatibility macros */
#define DL_DEBUG_VECT_name_length(_payload) pprzlink_get_DEBUG_VECT_name_length(_payload)
#define DL_DEBUG_VECT_name(_payload) pprzlink_get_DL_DEBUG_VECT_name(_payload)
#define DL_DEBUG_VECT_vector_length(_payload) pprzlink_get_DEBUG_VECT_vector_length(_payload)
#define DL_DEBUG_VECT_vector(_payload) pprzlink_get_DL_DEBUG_VECT_vector(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DEBUG_VECT_H_

