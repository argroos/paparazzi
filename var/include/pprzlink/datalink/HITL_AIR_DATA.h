/** @file
 *  @brief PPRZLink message header for HITL_AIR_DATA in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_HITL_AIR_DATA_H_
#define _VAR_MESSAGES_datalink_HITL_AIR_DATA_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HITL_AIR_DATA 73
#define PPRZ_MSG_ID_HITL_AIR_DATA 73

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HITL_AIR_DATA _send_msg(HITL_AIR_DATA,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HITL_AIR_DATA message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _baro 
 * @param _airspeed 
 * @param _aoa 
 * @param _sideslip 
 * @param _update_flag bit 0: baro, bit 1: airspeed, bit 2: aoa, bit 3: sideslip
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_HITL_AIR_DATA(struct pprzlink_msg * msg, float *_baro, float *_airspeed, float *_aoa, float *_sideslip, uint8_t *_update_flag, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HITL_AIR_DATA, "HITL_AIR_DATA");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _baro, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _aoa, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sideslip, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _update_flag, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HITL_AIR_DATA pprz_msg_send_HITL_AIR_DATA
#define DOWNLINK_SEND_HITL_AIR_DATA(_trans, _dev, baro, airspeed, aoa, sideslip, update_flag, ac_id) pprz_msg_send_HITL_AIR_DATA(&((_trans).trans_tx), &((_dev).device), AC_ID, baro, airspeed, aoa, sideslip, update_flag, ac_id)
/**
 * Sends a HITL_AIR_DATA message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _baro 
 * @param _airspeed 
 * @param _aoa 
 * @param _sideslip 
 * @param _update_flag bit 0: baro, bit 1: airspeed, bit 2: aoa, bit 3: sideslip
 * @param _ac_id 
 */
static inline void pprz_msg_send_HITL_AIR_DATA(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_baro, float *_airspeed, float *_aoa, float *_sideslip, uint8_t *_update_flag, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HITL_AIR_DATA(&msg,_baro,_airspeed,_aoa,_sideslip,_update_flag,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HITL_AIR_DATA(_trans, _dev, baro, airspeed, aoa, sideslip, update_flag, ac_id) {}
static inline void pprz_send_msg_HITL_AIR_DATA(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_baro __attribute__((unused)), float *_airspeed __attribute__((unused)), float *_aoa __attribute__((unused)), float *_sideslip __attribute__((unused)), uint8_t *_update_flag __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field baro in message HITL_AIR_DATA
  *
  * @param _payload : a pointer to the HITL_AIR_DATA message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_AIR_DATA_baro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field airspeed in message HITL_AIR_DATA
  *
  * @param _payload : a pointer to the HITL_AIR_DATA message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_AIR_DATA_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field aoa in message HITL_AIR_DATA
  *
  * @param _payload : a pointer to the HITL_AIR_DATA message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_AIR_DATA_aoa(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field sideslip in message HITL_AIR_DATA
  *
  * @param _payload : a pointer to the HITL_AIR_DATA message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_AIR_DATA_sideslip(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field update_flag in message HITL_AIR_DATA
  *
  * @param _payload : a pointer to the HITL_AIR_DATA message
  * @return bit 0: baro, bit 1: airspeed, bit 2: aoa, bit 3: sideslip
  */
static inline uint8_t pprzlink_get_DL_HITL_AIR_DATA_update_flag(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 20);
}


/** Getter for field ac_id in message HITL_AIR_DATA
  *
  * @param _payload : a pointer to the HITL_AIR_DATA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_AIR_DATA_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 21);
}


/* Compatibility macros */
#define DL_HITL_AIR_DATA_baro(_payload) pprzlink_get_DL_HITL_AIR_DATA_baro(_payload)
#define DL_HITL_AIR_DATA_airspeed(_payload) pprzlink_get_DL_HITL_AIR_DATA_airspeed(_payload)
#define DL_HITL_AIR_DATA_aoa(_payload) pprzlink_get_DL_HITL_AIR_DATA_aoa(_payload)
#define DL_HITL_AIR_DATA_sideslip(_payload) pprzlink_get_DL_HITL_AIR_DATA_sideslip(_payload)
#define DL_HITL_AIR_DATA_update_flag(_payload) pprzlink_get_DL_HITL_AIR_DATA_update_flag(_payload)
#define DL_HITL_AIR_DATA_ac_id(_payload) pprzlink_get_DL_HITL_AIR_DATA_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_HITL_AIR_DATA_H_

