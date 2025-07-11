/** @file
 *  @brief PPRZLink message header for IMU_GYRO_RAW in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_IMU_GYRO_RAW_H_
#define _VAR_MESSAGES_telemetry_IMU_GYRO_RAW_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMU_GYRO_RAW 203
#define PPRZ_MSG_ID_IMU_GYRO_RAW 203

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMU_GYRO_RAW _send_msg(IMU_GYRO_RAW,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMU_GYRO_RAW message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _id 
 * @param _temp 
 * @param _gp 
 * @param _gq 
 * @param _gr 
 */
static inline void pprzlink_msg_v2_send_IMU_GYRO_RAW(struct pprzlink_msg * msg, uint8_t *_id, float *_temp, int32_t *_gp, int32_t *_gq, int32_t *_gr) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMU_GYRO_RAW, "IMU_GYRO_RAW");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _gp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _gq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _gr, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMU_GYRO_RAW pprz_msg_send_IMU_GYRO_RAW
#define DOWNLINK_SEND_IMU_GYRO_RAW(_trans, _dev, id, temp, gp, gq, gr) pprz_msg_send_IMU_GYRO_RAW(&((_trans).trans_tx), &((_dev).device), AC_ID, id, temp, gp, gq, gr)
/**
 * Sends a IMU_GYRO_RAW message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _id 
 * @param _temp 
 * @param _gp 
 * @param _gq 
 * @param _gr 
 */
static inline void pprz_msg_send_IMU_GYRO_RAW(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_id, float *_temp, int32_t *_gp, int32_t *_gq, int32_t *_gr) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMU_GYRO_RAW(&msg,_id,_temp,_gp,_gq,_gr);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMU_GYRO_RAW(_trans, _dev, id, temp, gp, gq, gr) {}
static inline void pprz_send_msg_IMU_GYRO_RAW(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_id __attribute__((unused)), float *_temp __attribute__((unused)), int32_t *_gp __attribute__((unused)), int32_t *_gq __attribute__((unused)), int32_t *_gr __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field id in message IMU_GYRO_RAW
  *
  * @param _payload : a pointer to the IMU_GYRO_RAW message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMU_GYRO_RAW_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field temp in message IMU_GYRO_RAW
  *
  * @param _payload : a pointer to the IMU_GYRO_RAW message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_GYRO_RAW_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 5);
}


/** Getter for field gp in message IMU_GYRO_RAW
  *
  * @param _payload : a pointer to the IMU_GYRO_RAW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMU_GYRO_RAW_gp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 9);
}


/** Getter for field gq in message IMU_GYRO_RAW
  *
  * @param _payload : a pointer to the IMU_GYRO_RAW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMU_GYRO_RAW_gq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 13);
}


/** Getter for field gr in message IMU_GYRO_RAW
  *
  * @param _payload : a pointer to the IMU_GYRO_RAW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMU_GYRO_RAW_gr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 17);
}


/* Compatibility macros */
#define DL_IMU_GYRO_RAW_id(_payload) pprzlink_get_DL_IMU_GYRO_RAW_id(_payload)
#define DL_IMU_GYRO_RAW_temp(_payload) pprzlink_get_DL_IMU_GYRO_RAW_temp(_payload)
#define DL_IMU_GYRO_RAW_gp(_payload) pprzlink_get_DL_IMU_GYRO_RAW_gp(_payload)
#define DL_IMU_GYRO_RAW_gq(_payload) pprzlink_get_DL_IMU_GYRO_RAW_gq(_payload)
#define DL_IMU_GYRO_RAW_gr(_payload) pprzlink_get_DL_IMU_GYRO_RAW_gr(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_IMU_GYRO_RAW_H_

