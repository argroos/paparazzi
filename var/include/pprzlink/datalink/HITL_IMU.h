/** @file
 *  @brief PPRZLink message header for HITL_IMU in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_HITL_IMU_H_
#define _VAR_MESSAGES_datalink_HITL_IMU_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HITL_IMU 70
#define PPRZ_MSG_ID_HITL_IMU 70

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HITL_IMU _send_msg(HITL_IMU,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HITL_IMU message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _gp 
 * @param _gq 
 * @param _gr 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _mx 
 * @param _my 
 * @param _mz 
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_HITL_IMU(struct pprzlink_msg * msg, float *_gp, float *_gq, float *_gr, float *_ax, float *_ay, float *_az, float *_mx, float *_my, float *_mz, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HITL_IMU, "HITL_IMU");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gr, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ax, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ay, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _az, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _my, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HITL_IMU pprz_msg_send_HITL_IMU
#define DOWNLINK_SEND_HITL_IMU(_trans, _dev, gp, gq, gr, ax, ay, az, mx, my, mz, ac_id) pprz_msg_send_HITL_IMU(&((_trans).trans_tx), &((_dev).device), AC_ID, gp, gq, gr, ax, ay, az, mx, my, mz, ac_id)
/**
 * Sends a HITL_IMU message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _gp 
 * @param _gq 
 * @param _gr 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _mx 
 * @param _my 
 * @param _mz 
 * @param _ac_id 
 */
static inline void pprz_msg_send_HITL_IMU(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_gp, float *_gq, float *_gr, float *_ax, float *_ay, float *_az, float *_mx, float *_my, float *_mz, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HITL_IMU(&msg,_gp,_gq,_gr,_ax,_ay,_az,_mx,_my,_mz,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HITL_IMU(_trans, _dev, gp, gq, gr, ax, ay, az, mx, my, mz, ac_id) {}
static inline void pprz_send_msg_HITL_IMU(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_gp __attribute__((unused)), float *_gq __attribute__((unused)), float *_gr __attribute__((unused)), float *_ax __attribute__((unused)), float *_ay __attribute__((unused)), float *_az __attribute__((unused)), float *_mx __attribute__((unused)), float *_my __attribute__((unused)), float *_mz __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field gp in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_gp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field gq in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_gq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field gr in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_gr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field ax in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_ax(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field ay in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_ay(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field az in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_az(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field mx in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_mx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field my in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_my(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field mz in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_IMU_mz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field ac_id in message HITL_IMU
  *
  * @param _payload : a pointer to the HITL_IMU message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_IMU_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 40);
}


/* Compatibility macros */
#define DL_HITL_IMU_gp(_payload) pprzlink_get_DL_HITL_IMU_gp(_payload)
#define DL_HITL_IMU_gq(_payload) pprzlink_get_DL_HITL_IMU_gq(_payload)
#define DL_HITL_IMU_gr(_payload) pprzlink_get_DL_HITL_IMU_gr(_payload)
#define DL_HITL_IMU_ax(_payload) pprzlink_get_DL_HITL_IMU_ax(_payload)
#define DL_HITL_IMU_ay(_payload) pprzlink_get_DL_HITL_IMU_ay(_payload)
#define DL_HITL_IMU_az(_payload) pprzlink_get_DL_HITL_IMU_az(_payload)
#define DL_HITL_IMU_mx(_payload) pprzlink_get_DL_HITL_IMU_mx(_payload)
#define DL_HITL_IMU_my(_payload) pprzlink_get_DL_HITL_IMU_my(_payload)
#define DL_HITL_IMU_mz(_payload) pprzlink_get_DL_HITL_IMU_mz(_payload)
#define DL_HITL_IMU_ac_id(_payload) pprzlink_get_DL_HITL_IMU_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_HITL_IMU_H_

