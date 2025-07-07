/** @file
 *  @brief PPRZLink message header for AIRSPEED_RAW in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AIRSPEED_RAW_H_
#define _VAR_MESSAGES_telemetry_AIRSPEED_RAW_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AIRSPEED_RAW 138
#define PPRZ_MSG_ID_AIRSPEED_RAW 138

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AIRSPEED_RAW _send_msg(AIRSPEED_RAW,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AIRSPEED_RAW message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sensor_id 
 * @param _raw 
 * @param _offset 
 * @param _diffPress 
 * @param _temperature 
 * @param _airspeed 
 */
static inline void pprzlink_msg_v2_send_AIRSPEED_RAW(struct pprzlink_msg * msg, uint8_t *_sensor_id, uint16_t *_raw, float *_offset, float *_diffPress, float *_temperature, float *_airspeed) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+2+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+2+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AIRSPEED_RAW, "AIRSPEED_RAW");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _sensor_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _raw, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _offset, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _diffPress, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temperature, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AIRSPEED_RAW pprz_msg_send_AIRSPEED_RAW
#define DOWNLINK_SEND_AIRSPEED_RAW(_trans, _dev, sensor_id, raw, offset, diffPress, temperature, airspeed) pprz_msg_send_AIRSPEED_RAW(&((_trans).trans_tx), &((_dev).device), AC_ID, sensor_id, raw, offset, diffPress, temperature, airspeed)
/**
 * Sends a AIRSPEED_RAW message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sensor_id 
 * @param _raw 
 * @param _offset 
 * @param _diffPress 
 * @param _temperature 
 * @param _airspeed 
 */
static inline void pprz_msg_send_AIRSPEED_RAW(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_sensor_id, uint16_t *_raw, float *_offset, float *_diffPress, float *_temperature, float *_airspeed) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AIRSPEED_RAW(&msg,_sensor_id,_raw,_offset,_diffPress,_temperature,_airspeed);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AIRSPEED_RAW(_trans, _dev, sensor_id, raw, offset, diffPress, temperature, airspeed) {}
static inline void pprz_send_msg_AIRSPEED_RAW(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_sensor_id __attribute__((unused)), uint16_t *_raw __attribute__((unused)), float *_offset __attribute__((unused)), float *_diffPress __attribute__((unused)), float *_temperature __attribute__((unused)), float *_airspeed __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sensor_id in message AIRSPEED_RAW
  *
  * @param _payload : a pointer to the AIRSPEED_RAW message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_AIRSPEED_RAW_sensor_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field raw in message AIRSPEED_RAW
  *
  * @param _payload : a pointer to the AIRSPEED_RAW message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_AIRSPEED_RAW_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 5);
}


/** Getter for field offset in message AIRSPEED_RAW
  *
  * @param _payload : a pointer to the AIRSPEED_RAW message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_RAW_offset(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 7);
}


/** Getter for field diffPress in message AIRSPEED_RAW
  *
  * @param _payload : a pointer to the AIRSPEED_RAW message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_RAW_diffPress(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 11);
}


/** Getter for field temperature in message AIRSPEED_RAW
  *
  * @param _payload : a pointer to the AIRSPEED_RAW message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_RAW_temperature(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 15);
}


/** Getter for field airspeed in message AIRSPEED_RAW
  *
  * @param _payload : a pointer to the AIRSPEED_RAW message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_RAW_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 19);
}


/* Compatibility macros */
#define DL_AIRSPEED_RAW_sensor_id(_payload) pprzlink_get_DL_AIRSPEED_RAW_sensor_id(_payload)
#define DL_AIRSPEED_RAW_raw(_payload) pprzlink_get_DL_AIRSPEED_RAW_raw(_payload)
#define DL_AIRSPEED_RAW_offset(_payload) pprzlink_get_DL_AIRSPEED_RAW_offset(_payload)
#define DL_AIRSPEED_RAW_diffPress(_payload) pprzlink_get_DL_AIRSPEED_RAW_diffPress(_payload)
#define DL_AIRSPEED_RAW_temperature(_payload) pprzlink_get_DL_AIRSPEED_RAW_temperature(_payload)
#define DL_AIRSPEED_RAW_airspeed(_payload) pprzlink_get_DL_AIRSPEED_RAW_airspeed(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AIRSPEED_RAW_H_

