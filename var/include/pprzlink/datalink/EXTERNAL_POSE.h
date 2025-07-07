/** @file
 *  @brief PPRZLink message header for EXTERNAL_POSE in class datalink
 *
 *  
        Position, speed and orientation in local frame from a remote vision system
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_EXTERNAL_POSE_H_
#define _VAR_MESSAGES_datalink_EXTERNAL_POSE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_EXTERNAL_POSE 54
#define PPRZ_MSG_ID_EXTERNAL_POSE 54

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_EXTERNAL_POSE _send_msg(EXTERNAL_POSE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a EXTERNAL_POSE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id AC id for which the data is meant
 * @param _timestamp Timestamp from the measurement
 * @param _enu_x ENU x position in vision frame
 * @param _enu_y ENU y position in vision frame
 * @param _enu_z ENU z position in vision frame
 * @param _enu_xd ENU x speed in vision frame
 * @param _enu_yd ENU y speed in vision frame
 * @param _enu_zd ENU z speed in vision frame
 * @param _body_qi Body quaternion i in vision frame
 * @param _body_qx Body quaternion x in vision frame
 * @param _body_qy Body quaternion y in vision frame
 * @param _body_qz Body quaternion z in vision frame
 */
static inline void pprzlink_msg_v2_send_EXTERNAL_POSE(struct pprzlink_msg * msg, uint8_t *_ac_id, uint32_t *_timestamp, float *_enu_x, float *_enu_y, float *_enu_z, float *_enu_xd, float *_enu_yd, float *_enu_zd, float *_body_qi, float *_body_qx, float *_body_qy, float *_body_qz) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_EXTERNAL_POSE, "EXTERNAL_POSE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _timestamp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _body_qz, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_EXTERNAL_POSE pprz_msg_send_EXTERNAL_POSE
#define DOWNLINK_SEND_EXTERNAL_POSE(_trans, _dev, ac_id, timestamp, enu_x, enu_y, enu_z, enu_xd, enu_yd, enu_zd, body_qi, body_qx, body_qy, body_qz) pprz_msg_send_EXTERNAL_POSE(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, timestamp, enu_x, enu_y, enu_z, enu_xd, enu_yd, enu_zd, body_qi, body_qx, body_qy, body_qz)
/**
 * Sends a EXTERNAL_POSE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id AC id for which the data is meant
 * @param _timestamp Timestamp from the measurement
 * @param _enu_x ENU x position in vision frame
 * @param _enu_y ENU y position in vision frame
 * @param _enu_z ENU z position in vision frame
 * @param _enu_xd ENU x speed in vision frame
 * @param _enu_yd ENU y speed in vision frame
 * @param _enu_zd ENU z speed in vision frame
 * @param _body_qi Body quaternion i in vision frame
 * @param _body_qx Body quaternion x in vision frame
 * @param _body_qy Body quaternion y in vision frame
 * @param _body_qz Body quaternion z in vision frame
 */
static inline void pprz_msg_send_EXTERNAL_POSE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint32_t *_timestamp, float *_enu_x, float *_enu_y, float *_enu_z, float *_enu_xd, float *_enu_yd, float *_enu_zd, float *_body_qi, float *_body_qx, float *_body_qy, float *_body_qz) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_EXTERNAL_POSE(&msg,_ac_id,_timestamp,_enu_x,_enu_y,_enu_z,_enu_xd,_enu_yd,_enu_zd,_body_qi,_body_qx,_body_qy,_body_qz);
}


#else // DOWNLINK

#define DOWNLINK_SEND_EXTERNAL_POSE(_trans, _dev, ac_id, timestamp, enu_x, enu_y, enu_z, enu_xd, enu_yd, enu_zd, body_qi, body_qx, body_qy, body_qz) {}
static inline void pprz_send_msg_EXTERNAL_POSE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint32_t *_timestamp __attribute__((unused)), float *_enu_x __attribute__((unused)), float *_enu_y __attribute__((unused)), float *_enu_z __attribute__((unused)), float *_enu_xd __attribute__((unused)), float *_enu_yd __attribute__((unused)), float *_enu_zd __attribute__((unused)), float *_body_qi __attribute__((unused)), float *_body_qx __attribute__((unused)), float *_body_qy __attribute__((unused)), float *_body_qz __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return AC id for which the data is meant
  */
static inline uint8_t pprzlink_get_DL_EXTERNAL_POSE_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field timestamp in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return Timestamp from the measurement
  */
static inline uint32_t pprzlink_get_DL_EXTERNAL_POSE_timestamp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 5);
}


/** Getter for field enu_x in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return ENU x position in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_enu_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 9);
}


/** Getter for field enu_y in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return ENU y position in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_enu_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 13);
}


/** Getter for field enu_z in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return ENU z position in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_enu_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 17);
}


/** Getter for field enu_xd in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return ENU x speed in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_enu_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 21);
}


/** Getter for field enu_yd in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return ENU y speed in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_enu_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 25);
}


/** Getter for field enu_zd in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return ENU z speed in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_enu_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 29);
}


/** Getter for field body_qi in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return Body quaternion i in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_body_qi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 33);
}


/** Getter for field body_qx in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return Body quaternion x in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_body_qx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 37);
}


/** Getter for field body_qy in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return Body quaternion y in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_body_qy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 41);
}


/** Getter for field body_qz in message EXTERNAL_POSE
  *
  * @param _payload : a pointer to the EXTERNAL_POSE message
  * @return Body quaternion z in vision frame
  */
static inline float pprzlink_get_DL_EXTERNAL_POSE_body_qz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 45);
}


/* Compatibility macros */
#define DL_EXTERNAL_POSE_ac_id(_payload) pprzlink_get_DL_EXTERNAL_POSE_ac_id(_payload)
#define DL_EXTERNAL_POSE_timestamp(_payload) pprzlink_get_DL_EXTERNAL_POSE_timestamp(_payload)
#define DL_EXTERNAL_POSE_enu_x(_payload) pprzlink_get_DL_EXTERNAL_POSE_enu_x(_payload)
#define DL_EXTERNAL_POSE_enu_y(_payload) pprzlink_get_DL_EXTERNAL_POSE_enu_y(_payload)
#define DL_EXTERNAL_POSE_enu_z(_payload) pprzlink_get_DL_EXTERNAL_POSE_enu_z(_payload)
#define DL_EXTERNAL_POSE_enu_xd(_payload) pprzlink_get_DL_EXTERNAL_POSE_enu_xd(_payload)
#define DL_EXTERNAL_POSE_enu_yd(_payload) pprzlink_get_DL_EXTERNAL_POSE_enu_yd(_payload)
#define DL_EXTERNAL_POSE_enu_zd(_payload) pprzlink_get_DL_EXTERNAL_POSE_enu_zd(_payload)
#define DL_EXTERNAL_POSE_body_qi(_payload) pprzlink_get_DL_EXTERNAL_POSE_body_qi(_payload)
#define DL_EXTERNAL_POSE_body_qx(_payload) pprzlink_get_DL_EXTERNAL_POSE_body_qx(_payload)
#define DL_EXTERNAL_POSE_body_qy(_payload) pprzlink_get_DL_EXTERNAL_POSE_body_qy(_payload)
#define DL_EXTERNAL_POSE_body_qz(_payload) pprzlink_get_DL_EXTERNAL_POSE_body_qz(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_EXTERNAL_POSE_H_

