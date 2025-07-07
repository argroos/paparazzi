/** @file
 *  @brief PPRZLink message header for APPROACH_MOVING_TARGET in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_APPROACH_MOVING_TARGET_H_
#define _VAR_MESSAGES_telemetry_APPROACH_MOVING_TARGET_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_APPROACH_MOVING_TARGET 139
#define PPRZ_MSG_ID_APPROACH_MOVING_TARGET 139

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_APPROACH_MOVING_TARGET _send_msg(APPROACH_MOVING_TARGET,PPRZLINK_DEFAULT_VER)

/**
 * Sends a APPROACH_MOVING_TARGET message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ref_pos_x 
 * @param _ref_pos_y 
 * @param _ref_pos_z 
 * @param _ref_vel_x 
 * @param _ref_vel_y 
 * @param _ref_vel_z 
 * @param _distance 
 */
static inline void pprzlink_msg_v2_send_APPROACH_MOVING_TARGET(struct pprzlink_msg * msg, float *_ref_pos_x, float *_ref_pos_y, float *_ref_pos_z, float *_ref_vel_x, float *_ref_vel_y, float *_ref_vel_z, float *_distance) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_APPROACH_MOVING_TARGET, "APPROACH_MOVING_TARGET");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_pos_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_pos_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_pos_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_vel_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_vel_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_vel_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _distance, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_APPROACH_MOVING_TARGET pprz_msg_send_APPROACH_MOVING_TARGET
#define DOWNLINK_SEND_APPROACH_MOVING_TARGET(_trans, _dev, ref_pos_x, ref_pos_y, ref_pos_z, ref_vel_x, ref_vel_y, ref_vel_z, distance) pprz_msg_send_APPROACH_MOVING_TARGET(&((_trans).trans_tx), &((_dev).device), AC_ID, ref_pos_x, ref_pos_y, ref_pos_z, ref_vel_x, ref_vel_y, ref_vel_z, distance)
/**
 * Sends a APPROACH_MOVING_TARGET message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ref_pos_x 
 * @param _ref_pos_y 
 * @param _ref_pos_z 
 * @param _ref_vel_x 
 * @param _ref_vel_y 
 * @param _ref_vel_z 
 * @param _distance 
 */
static inline void pprz_msg_send_APPROACH_MOVING_TARGET(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_ref_pos_x, float *_ref_pos_y, float *_ref_pos_z, float *_ref_vel_x, float *_ref_vel_y, float *_ref_vel_z, float *_distance) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_APPROACH_MOVING_TARGET(&msg,_ref_pos_x,_ref_pos_y,_ref_pos_z,_ref_vel_x,_ref_vel_y,_ref_vel_z,_distance);
}


#else // DOWNLINK

#define DOWNLINK_SEND_APPROACH_MOVING_TARGET(_trans, _dev, ref_pos_x, ref_pos_y, ref_pos_z, ref_vel_x, ref_vel_y, ref_vel_z, distance) {}
static inline void pprz_send_msg_APPROACH_MOVING_TARGET(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_ref_pos_x __attribute__((unused)), float *_ref_pos_y __attribute__((unused)), float *_ref_pos_z __attribute__((unused)), float *_ref_vel_x __attribute__((unused)), float *_ref_vel_y __attribute__((unused)), float *_ref_vel_z __attribute__((unused)), float *_distance __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ref_pos_x in message APPROACH_MOVING_TARGET
  *
  * @param _payload : a pointer to the APPROACH_MOVING_TARGET message
  * @return 
  */
static inline float pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_pos_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field ref_pos_y in message APPROACH_MOVING_TARGET
  *
  * @param _payload : a pointer to the APPROACH_MOVING_TARGET message
  * @return 
  */
static inline float pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_pos_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field ref_pos_z in message APPROACH_MOVING_TARGET
  *
  * @param _payload : a pointer to the APPROACH_MOVING_TARGET message
  * @return 
  */
static inline float pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_pos_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field ref_vel_x in message APPROACH_MOVING_TARGET
  *
  * @param _payload : a pointer to the APPROACH_MOVING_TARGET message
  * @return 
  */
static inline float pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_vel_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field ref_vel_y in message APPROACH_MOVING_TARGET
  *
  * @param _payload : a pointer to the APPROACH_MOVING_TARGET message
  * @return 
  */
static inline float pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_vel_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field ref_vel_z in message APPROACH_MOVING_TARGET
  *
  * @param _payload : a pointer to the APPROACH_MOVING_TARGET message
  * @return 
  */
static inline float pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_vel_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field distance in message APPROACH_MOVING_TARGET
  *
  * @param _payload : a pointer to the APPROACH_MOVING_TARGET message
  * @return 
  */
static inline float pprzlink_get_DL_APPROACH_MOVING_TARGET_distance(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/* Compatibility macros */
#define DL_APPROACH_MOVING_TARGET_ref_pos_x(_payload) pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_pos_x(_payload)
#define DL_APPROACH_MOVING_TARGET_ref_pos_y(_payload) pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_pos_y(_payload)
#define DL_APPROACH_MOVING_TARGET_ref_pos_z(_payload) pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_pos_z(_payload)
#define DL_APPROACH_MOVING_TARGET_ref_vel_x(_payload) pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_vel_x(_payload)
#define DL_APPROACH_MOVING_TARGET_ref_vel_y(_payload) pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_vel_y(_payload)
#define DL_APPROACH_MOVING_TARGET_ref_vel_z(_payload) pprzlink_get_DL_APPROACH_MOVING_TARGET_ref_vel_z(_payload)
#define DL_APPROACH_MOVING_TARGET_distance(_payload) pprzlink_get_DL_APPROACH_MOVING_TARGET_distance(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_APPROACH_MOVING_TARGET_H_

