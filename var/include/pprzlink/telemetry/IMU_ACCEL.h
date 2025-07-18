/** @file
 *  @brief PPRZLink message header for IMU_ACCEL in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_IMU_ACCEL_H_
#define _VAR_MESSAGES_telemetry_IMU_ACCEL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMU_ACCEL 202
#define PPRZ_MSG_ID_IMU_ACCEL 202

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMU_ACCEL _send_msg(IMU_ACCEL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMU_ACCEL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _id 
 * @param _ax 
 * @param _ay 
 * @param _az 
 */
static inline void pprzlink_msg_v2_send_IMU_ACCEL(struct pprzlink_msg * msg, uint8_t *_id, float *_ax, float *_ay, float *_az) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMU_ACCEL, "IMU_ACCEL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ax, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ay, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _az, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMU_ACCEL pprz_msg_send_IMU_ACCEL
#define DOWNLINK_SEND_IMU_ACCEL(_trans, _dev, id, ax, ay, az) pprz_msg_send_IMU_ACCEL(&((_trans).trans_tx), &((_dev).device), AC_ID, id, ax, ay, az)
/**
 * Sends a IMU_ACCEL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _id 
 * @param _ax 
 * @param _ay 
 * @param _az 
 */
static inline void pprz_msg_send_IMU_ACCEL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_id, float *_ax, float *_ay, float *_az) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMU_ACCEL(&msg,_id,_ax,_ay,_az);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMU_ACCEL(_trans, _dev, id, ax, ay, az) {}
static inline void pprz_send_msg_IMU_ACCEL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_id __attribute__((unused)), float *_ax __attribute__((unused)), float *_ay __attribute__((unused)), float *_az __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field id in message IMU_ACCEL
  *
  * @param _payload : a pointer to the IMU_ACCEL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMU_ACCEL_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field ax in message IMU_ACCEL
  *
  * @param _payload : a pointer to the IMU_ACCEL message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_ACCEL_ax(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 5);
}


/** Getter for field ay in message IMU_ACCEL
  *
  * @param _payload : a pointer to the IMU_ACCEL message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_ACCEL_ay(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 9);
}


/** Getter for field az in message IMU_ACCEL
  *
  * @param _payload : a pointer to the IMU_ACCEL message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_ACCEL_az(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 13);
}


/* Compatibility macros */
#define DL_IMU_ACCEL_id(_payload) pprzlink_get_DL_IMU_ACCEL_id(_payload)
#define DL_IMU_ACCEL_ax(_payload) pprzlink_get_DL_IMU_ACCEL_ax(_payload)
#define DL_IMU_ACCEL_ay(_payload) pprzlink_get_DL_IMU_ACCEL_ay(_payload)
#define DL_IMU_ACCEL_az(_payload) pprzlink_get_DL_IMU_ACCEL_az(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_IMU_ACCEL_H_

