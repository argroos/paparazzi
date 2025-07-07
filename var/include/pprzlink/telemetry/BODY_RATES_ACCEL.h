/** @file
 *  @brief PPRZLink message header for BODY_RATES_ACCEL in class telemetry
 *
 *  
        Rates and Acceleration in the body frame
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_BODY_RATES_ACCEL_H_
#define _VAR_MESSAGES_telemetry_BODY_RATES_ACCEL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_BODY_RATES_ACCEL 76
#define PPRZ_MSG_ID_BODY_RATES_ACCEL 76

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_BODY_RATES_ACCEL _send_msg(BODY_RATES_ACCEL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a BODY_RATES_ACCEL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _ax 
 * @param _ay 
 * @param _az 
 */
static inline void pprzlink_msg_v2_send_BODY_RATES_ACCEL(struct pprzlink_msg * msg, float *_p, float *_q, float *_r, int32_t *_ax, int32_t *_ay, int32_t *_az) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_BODY_RATES_ACCEL, "BODY_RATES_ACCEL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ax, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ay, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _az, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_BODY_RATES_ACCEL pprz_msg_send_BODY_RATES_ACCEL
#define DOWNLINK_SEND_BODY_RATES_ACCEL(_trans, _dev, p, q, r, ax, ay, az) pprz_msg_send_BODY_RATES_ACCEL(&((_trans).trans_tx), &((_dev).device), AC_ID, p, q, r, ax, ay, az)
/**
 * Sends a BODY_RATES_ACCEL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _ax 
 * @param _ay 
 * @param _az 
 */
static inline void pprz_msg_send_BODY_RATES_ACCEL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_p, float *_q, float *_r, int32_t *_ax, int32_t *_ay, int32_t *_az) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_BODY_RATES_ACCEL(&msg,_p,_q,_r,_ax,_ay,_az);
}


#else // DOWNLINK

#define DOWNLINK_SEND_BODY_RATES_ACCEL(_trans, _dev, p, q, r, ax, ay, az) {}
static inline void pprz_send_msg_BODY_RATES_ACCEL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_p __attribute__((unused)), float *_q __attribute__((unused)), float *_r __attribute__((unused)), int32_t *_ax __attribute__((unused)), int32_t *_ay __attribute__((unused)), int32_t *_az __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field p in message BODY_RATES_ACCEL
  *
  * @param _payload : a pointer to the BODY_RATES_ACCEL message
  * @return 
  */
static inline float pprzlink_get_DL_BODY_RATES_ACCEL_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field q in message BODY_RATES_ACCEL
  *
  * @param _payload : a pointer to the BODY_RATES_ACCEL message
  * @return 
  */
static inline float pprzlink_get_DL_BODY_RATES_ACCEL_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field r in message BODY_RATES_ACCEL
  *
  * @param _payload : a pointer to the BODY_RATES_ACCEL message
  * @return 
  */
static inline float pprzlink_get_DL_BODY_RATES_ACCEL_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field ax in message BODY_RATES_ACCEL
  *
  * @param _payload : a pointer to the BODY_RATES_ACCEL message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BODY_RATES_ACCEL_ax(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field ay in message BODY_RATES_ACCEL
  *
  * @param _payload : a pointer to the BODY_RATES_ACCEL message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BODY_RATES_ACCEL_ay(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field az in message BODY_RATES_ACCEL
  *
  * @param _payload : a pointer to the BODY_RATES_ACCEL message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BODY_RATES_ACCEL_az(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/* Compatibility macros */
#define DL_BODY_RATES_ACCEL_p(_payload) pprzlink_get_DL_BODY_RATES_ACCEL_p(_payload)
#define DL_BODY_RATES_ACCEL_q(_payload) pprzlink_get_DL_BODY_RATES_ACCEL_q(_payload)
#define DL_BODY_RATES_ACCEL_r(_payload) pprzlink_get_DL_BODY_RATES_ACCEL_r(_payload)
#define DL_BODY_RATES_ACCEL_ax(_payload) pprzlink_get_DL_BODY_RATES_ACCEL_ax(_payload)
#define DL_BODY_RATES_ACCEL_ay(_payload) pprzlink_get_DL_BODY_RATES_ACCEL_ay(_payload)
#define DL_BODY_RATES_ACCEL_az(_payload) pprzlink_get_DL_BODY_RATES_ACCEL_az(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_BODY_RATES_ACCEL_H_

