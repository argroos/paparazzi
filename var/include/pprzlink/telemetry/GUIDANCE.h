/** @file
 *  @brief PPRZLink message header for GUIDANCE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GUIDANCE_H_
#define _VAR_MESSAGES_telemetry_GUIDANCE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GUIDANCE 184
#define PPRZ_MSG_ID_GUIDANCE 184

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GUIDANCE _send_msg(GUIDANCE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GUIDANCE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _pos_N_ref 
 * @param _pos_E_ref 
 * @param _pos_D_ref 
 * @param _pos_N 
 * @param _pos_E 
 * @param _pos_D 
 * @param _vel_N_ref 
 * @param _vel_E_ref 
 * @param _vel_D_ref 
 * @param _vel_N 
 * @param _vel_E 
 * @param _vel_D 
 * @param _acc_N_ref 
 * @param _acc_E_ref 
 * @param _acc_D_ref 
 * @param _acc_N 
 * @param _acc_E 
 * @param _acc_D 
 * @param _jerk_N 
 * @param _jerk_E 
 * @param _jerk_D 
 */
static inline void pprzlink_msg_v2_send_GUIDANCE(struct pprzlink_msg * msg, float *_pos_N_ref, float *_pos_E_ref, float *_pos_D_ref, float *_pos_N, float *_pos_E, float *_pos_D, float *_vel_N_ref, float *_vel_E_ref, float *_vel_D_ref, float *_vel_N, float *_vel_E, float *_vel_D, float *_acc_N_ref, float *_acc_E_ref, float *_acc_D_ref, float *_acc_N, float *_acc_E, float *_acc_D, float *_jerk_N, float *_jerk_E, float *_jerk_D) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GUIDANCE, "GUIDANCE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_N_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_E_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_D_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_N, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_E, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_D, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_N_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_E_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_D_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_N, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_E, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_D, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_N_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_E_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_D_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_N, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_E, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_D, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _jerk_N, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _jerk_E, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _jerk_D, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GUIDANCE pprz_msg_send_GUIDANCE
#define DOWNLINK_SEND_GUIDANCE(_trans, _dev, pos_N_ref, pos_E_ref, pos_D_ref, pos_N, pos_E, pos_D, vel_N_ref, vel_E_ref, vel_D_ref, vel_N, vel_E, vel_D, acc_N_ref, acc_E_ref, acc_D_ref, acc_N, acc_E, acc_D, jerk_N, jerk_E, jerk_D) pprz_msg_send_GUIDANCE(&((_trans).trans_tx), &((_dev).device), AC_ID, pos_N_ref, pos_E_ref, pos_D_ref, pos_N, pos_E, pos_D, vel_N_ref, vel_E_ref, vel_D_ref, vel_N, vel_E, vel_D, acc_N_ref, acc_E_ref, acc_D_ref, acc_N, acc_E, acc_D, jerk_N, jerk_E, jerk_D)
/**
 * Sends a GUIDANCE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _pos_N_ref 
 * @param _pos_E_ref 
 * @param _pos_D_ref 
 * @param _pos_N 
 * @param _pos_E 
 * @param _pos_D 
 * @param _vel_N_ref 
 * @param _vel_E_ref 
 * @param _vel_D_ref 
 * @param _vel_N 
 * @param _vel_E 
 * @param _vel_D 
 * @param _acc_N_ref 
 * @param _acc_E_ref 
 * @param _acc_D_ref 
 * @param _acc_N 
 * @param _acc_E 
 * @param _acc_D 
 * @param _jerk_N 
 * @param _jerk_E 
 * @param _jerk_D 
 */
static inline void pprz_msg_send_GUIDANCE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_pos_N_ref, float *_pos_E_ref, float *_pos_D_ref, float *_pos_N, float *_pos_E, float *_pos_D, float *_vel_N_ref, float *_vel_E_ref, float *_vel_D_ref, float *_vel_N, float *_vel_E, float *_vel_D, float *_acc_N_ref, float *_acc_E_ref, float *_acc_D_ref, float *_acc_N, float *_acc_E, float *_acc_D, float *_jerk_N, float *_jerk_E, float *_jerk_D) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GUIDANCE(&msg,_pos_N_ref,_pos_E_ref,_pos_D_ref,_pos_N,_pos_E,_pos_D,_vel_N_ref,_vel_E_ref,_vel_D_ref,_vel_N,_vel_E,_vel_D,_acc_N_ref,_acc_E_ref,_acc_D_ref,_acc_N,_acc_E,_acc_D,_jerk_N,_jerk_E,_jerk_D);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GUIDANCE(_trans, _dev, pos_N_ref, pos_E_ref, pos_D_ref, pos_N, pos_E, pos_D, vel_N_ref, vel_E_ref, vel_D_ref, vel_N, vel_E, vel_D, acc_N_ref, acc_E_ref, acc_D_ref, acc_N, acc_E, acc_D, jerk_N, jerk_E, jerk_D) {}
static inline void pprz_send_msg_GUIDANCE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_pos_N_ref __attribute__((unused)), float *_pos_E_ref __attribute__((unused)), float *_pos_D_ref __attribute__((unused)), float *_pos_N __attribute__((unused)), float *_pos_E __attribute__((unused)), float *_pos_D __attribute__((unused)), float *_vel_N_ref __attribute__((unused)), float *_vel_E_ref __attribute__((unused)), float *_vel_D_ref __attribute__((unused)), float *_vel_N __attribute__((unused)), float *_vel_E __attribute__((unused)), float *_vel_D __attribute__((unused)), float *_acc_N_ref __attribute__((unused)), float *_acc_E_ref __attribute__((unused)), float *_acc_D_ref __attribute__((unused)), float *_acc_N __attribute__((unused)), float *_acc_E __attribute__((unused)), float *_acc_D __attribute__((unused)), float *_jerk_N __attribute__((unused)), float *_jerk_E __attribute__((unused)), float *_jerk_D __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field pos_N_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_pos_N_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field pos_E_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_pos_E_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field pos_D_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_pos_D_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field pos_N in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_pos_N(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field pos_E in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_pos_E(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field pos_D in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_pos_D(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field vel_N_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_vel_N_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field vel_E_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_vel_E_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field vel_D_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_vel_D_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field vel_N in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_vel_N(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field vel_E in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_vel_E(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field vel_D in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_vel_D(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field acc_N_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_acc_N_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/** Getter for field acc_E_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_acc_E_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field acc_D_ref in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_acc_D_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/** Getter for field acc_N in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_acc_N(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 64);
}


/** Getter for field acc_E in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_acc_E(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 68);
}


/** Getter for field acc_D in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_acc_D(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 72);
}


/** Getter for field jerk_N in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_jerk_N(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 76);
}


/** Getter for field jerk_E in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_jerk_E(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 80);
}


/** Getter for field jerk_D in message GUIDANCE
  *
  * @param _payload : a pointer to the GUIDANCE message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_jerk_D(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 84);
}


/* Compatibility macros */
#define DL_GUIDANCE_pos_N_ref(_payload) pprzlink_get_DL_GUIDANCE_pos_N_ref(_payload)
#define DL_GUIDANCE_pos_E_ref(_payload) pprzlink_get_DL_GUIDANCE_pos_E_ref(_payload)
#define DL_GUIDANCE_pos_D_ref(_payload) pprzlink_get_DL_GUIDANCE_pos_D_ref(_payload)
#define DL_GUIDANCE_pos_N(_payload) pprzlink_get_DL_GUIDANCE_pos_N(_payload)
#define DL_GUIDANCE_pos_E(_payload) pprzlink_get_DL_GUIDANCE_pos_E(_payload)
#define DL_GUIDANCE_pos_D(_payload) pprzlink_get_DL_GUIDANCE_pos_D(_payload)
#define DL_GUIDANCE_vel_N_ref(_payload) pprzlink_get_DL_GUIDANCE_vel_N_ref(_payload)
#define DL_GUIDANCE_vel_E_ref(_payload) pprzlink_get_DL_GUIDANCE_vel_E_ref(_payload)
#define DL_GUIDANCE_vel_D_ref(_payload) pprzlink_get_DL_GUIDANCE_vel_D_ref(_payload)
#define DL_GUIDANCE_vel_N(_payload) pprzlink_get_DL_GUIDANCE_vel_N(_payload)
#define DL_GUIDANCE_vel_E(_payload) pprzlink_get_DL_GUIDANCE_vel_E(_payload)
#define DL_GUIDANCE_vel_D(_payload) pprzlink_get_DL_GUIDANCE_vel_D(_payload)
#define DL_GUIDANCE_acc_N_ref(_payload) pprzlink_get_DL_GUIDANCE_acc_N_ref(_payload)
#define DL_GUIDANCE_acc_E_ref(_payload) pprzlink_get_DL_GUIDANCE_acc_E_ref(_payload)
#define DL_GUIDANCE_acc_D_ref(_payload) pprzlink_get_DL_GUIDANCE_acc_D_ref(_payload)
#define DL_GUIDANCE_acc_N(_payload) pprzlink_get_DL_GUIDANCE_acc_N(_payload)
#define DL_GUIDANCE_acc_E(_payload) pprzlink_get_DL_GUIDANCE_acc_E(_payload)
#define DL_GUIDANCE_acc_D(_payload) pprzlink_get_DL_GUIDANCE_acc_D(_payload)
#define DL_GUIDANCE_jerk_N(_payload) pprzlink_get_DL_GUIDANCE_jerk_N(_payload)
#define DL_GUIDANCE_jerk_E(_payload) pprzlink_get_DL_GUIDANCE_jerk_E(_payload)
#define DL_GUIDANCE_jerk_D(_payload) pprzlink_get_DL_GUIDANCE_jerk_D(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GUIDANCE_H_

