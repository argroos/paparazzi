/** @file
 *  @brief PPRZLink message header for EXTERNAL_POSE_DOWN in class telemetry
 *
 *  
        Position, speed and orientation in local frame from a remote vision system
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_EXTERNAL_POSE_DOWN_H_
#define _VAR_MESSAGES_telemetry_EXTERNAL_POSE_DOWN_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_EXTERNAL_POSE_DOWN 46
#define PPRZ_MSG_ID_EXTERNAL_POSE_DOWN 46

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_EXTERNAL_POSE_DOWN _send_msg(EXTERNAL_POSE_DOWN,PPRZLINK_DEFAULT_VER)

/**
 * Sends a EXTERNAL_POSE_DOWN message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _timestamp Timestamp from the measurement
 * @param _ned_x NED x position in vision frame
 * @param _ned_y NED y position in vision frame
 * @param _ned_z NED z position in vision frame
 * @param _ned_xd NED x speed in vision frame
 * @param _ned_yd NED y speed in vision frame
 * @param _ned_zd NED z speed in vision frame
 * @param _body_qi Body quaternion i in NED to body
 * @param _body_qx Body quaternion x in NED to body
 * @param _body_qy Body quaternion y in NED to body
 * @param _body_qz Body quaternion z in NED to body
 */
static inline void pprzlink_msg_v2_send_EXTERNAL_POSE_DOWN(struct pprzlink_msg * msg, float *_timestamp, float *_ned_x, float *_ned_y, float *_ned_z, float *_ned_xd, float *_ned_yd, float *_ned_zd, float *_body_qi, float *_body_qx, float *_body_qy, float *_body_qz) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_EXTERNAL_POSE_DOWN, "EXTERNAL_POSE_DOWN");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _timestamp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ned_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ned_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ned_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ned_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ned_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ned_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qz, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_EXTERNAL_POSE_DOWN pprz_msg_send_EXTERNAL_POSE_DOWN
#define DOWNLINK_SEND_EXTERNAL_POSE_DOWN(_trans, _dev, timestamp, ned_x, ned_y, ned_z, ned_xd, ned_yd, ned_zd, body_qi, body_qx, body_qy, body_qz) pprz_msg_send_EXTERNAL_POSE_DOWN(&((_trans).trans_tx), &((_dev).device), AC_ID, timestamp, ned_x, ned_y, ned_z, ned_xd, ned_yd, ned_zd, body_qi, body_qx, body_qy, body_qz)
/**
 * Sends a EXTERNAL_POSE_DOWN message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _timestamp Timestamp from the measurement
 * @param _ned_x NED x position in vision frame
 * @param _ned_y NED y position in vision frame
 * @param _ned_z NED z position in vision frame
 * @param _ned_xd NED x speed in vision frame
 * @param _ned_yd NED y speed in vision frame
 * @param _ned_zd NED z speed in vision frame
 * @param _body_qi Body quaternion i in NED to body
 * @param _body_qx Body quaternion x in NED to body
 * @param _body_qy Body quaternion y in NED to body
 * @param _body_qz Body quaternion z in NED to body
 */
static inline void pprz_msg_send_EXTERNAL_POSE_DOWN(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_timestamp, float *_ned_x, float *_ned_y, float *_ned_z, float *_ned_xd, float *_ned_yd, float *_ned_zd, float *_body_qi, float *_body_qx, float *_body_qy, float *_body_qz) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_EXTERNAL_POSE_DOWN(&msg,_timestamp,_ned_x,_ned_y,_ned_z,_ned_xd,_ned_yd,_ned_zd,_body_qi,_body_qx,_body_qy,_body_qz);
}


#else // DOWNLINK

#define DOWNLINK_SEND_EXTERNAL_POSE_DOWN(_trans, _dev, timestamp, ned_x, ned_y, ned_z, ned_xd, ned_yd, ned_zd, body_qi, body_qx, body_qy, body_qz) {}
static inline void pprz_send_msg_EXTERNAL_POSE_DOWN(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_timestamp __attribute__((unused)), float *_ned_x __attribute__((unused)), float *_ned_y __attribute__((unused)), float *_ned_z __attribute__((unused)), float *_ned_xd __attribute__((unused)), float *_ned_yd __attribute__((unused)), float *_ned_zd __attribute__((unused)), float *_body_qi __attribute__((unused)), float *_body_qx __attribute__((unused)), float *_body_qy __attribute__((unused)), float *_body_qz __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field timestamp in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return Timestamp from the measurement
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_timestamp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field ned_x in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return NED x position in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field ned_y in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return NED y position in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field ned_z in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return NED z position in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field ned_xd in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return NED x speed in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field ned_yd in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return NED y speed in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field ned_zd in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return NED z speed in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field body_qi in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return Body quaternion i in NED to body
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field body_qx in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return Body quaternion x in NED to body
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field body_qy in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return Body quaternion y in NED to body
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field body_qz in message EXTERNAL_POSE_DOWN
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_DOWN message
  * @return Body quaternion z in NED to body
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/* Compatibility macros */
#define DL_EXTERNAL_POSE_DOWN_timestamp(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_timestamp(_payload)
#define DL_EXTERNAL_POSE_DOWN_ned_x(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_x(_payload)
#define DL_EXTERNAL_POSE_DOWN_ned_y(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_y(_payload)
#define DL_EXTERNAL_POSE_DOWN_ned_z(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_z(_payload)
#define DL_EXTERNAL_POSE_DOWN_ned_xd(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_xd(_payload)
#define DL_EXTERNAL_POSE_DOWN_ned_yd(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_yd(_payload)
#define DL_EXTERNAL_POSE_DOWN_ned_zd(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_ned_zd(_payload)
#define DL_EXTERNAL_POSE_DOWN_body_qi(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qi(_payload)
#define DL_EXTERNAL_POSE_DOWN_body_qx(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qx(_payload)
#define DL_EXTERNAL_POSE_DOWN_body_qy(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qy(_payload)
#define DL_EXTERNAL_POSE_DOWN_body_qz(_payload) pprzlink_get_DL_EXTERNAL_POSE_DOWN_body_qz(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_EXTERNAL_POSE_DOWN_H_

