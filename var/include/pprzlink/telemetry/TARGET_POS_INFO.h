/** @file
 *  @brief PPRZLink message header for TARGET_POS_INFO in class telemetry
 *
 *  
        Global position, speed and ID of a target for functions like 'Follow Me'
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_TARGET_POS_INFO_H_
#define _VAR_MESSAGES_telemetry_TARGET_POS_INFO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TARGET_POS_INFO 95
#define PPRZ_MSG_ID_TARGET_POS_INFO 95

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TARGET_POS_INFO _send_msg(TARGET_POS_INFO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TARGET_POS_INFO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 * @param _speed Ground speed
 * @param _climb Climb speed
 * @param _course 
 * @param _heading 
 * @param _off_heading Offset heading
 * @param _off_distance Offset distance
 * @param _off_height Offset height
 */
static inline void pprzlink_msg_v2_send_TARGET_POS_INFO(struct pprzlink_msg * msg, int32_t *_lat, int32_t *_lon, int32_t *_alt, float *_speed, float *_climb, float *_course, float *_heading, float *_off_heading, float *_off_distance, float *_off_height) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TARGET_POS_INFO, "TARGET_POS_INFO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _speed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _climb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _heading, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _off_heading, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _off_distance, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _off_height, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TARGET_POS_INFO pprz_msg_send_TARGET_POS_INFO
#define DOWNLINK_SEND_TARGET_POS_INFO(_trans, _dev, lat, lon, alt, speed, climb, course, heading, off_heading, off_distance, off_height) pprz_msg_send_TARGET_POS_INFO(&((_trans).trans_tx), &((_dev).device), AC_ID, lat, lon, alt, speed, climb, course, heading, off_heading, off_distance, off_height)
/**
 * Sends a TARGET_POS_INFO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 * @param _speed Ground speed
 * @param _climb Climb speed
 * @param _course 
 * @param _heading 
 * @param _off_heading Offset heading
 * @param _off_distance Offset distance
 * @param _off_height Offset height
 */
static inline void pprz_msg_send_TARGET_POS_INFO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_lat, int32_t *_lon, int32_t *_alt, float *_speed, float *_climb, float *_course, float *_heading, float *_off_heading, float *_off_distance, float *_off_height) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TARGET_POS_INFO(&msg,_lat,_lon,_alt,_speed,_climb,_course,_heading,_off_heading,_off_distance,_off_height);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TARGET_POS_INFO(_trans, _dev, lat, lon, alt, speed, climb, course, heading, off_heading, off_distance, off_height) {}
static inline void pprz_send_msg_TARGET_POS_INFO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused)), float *_speed __attribute__((unused)), float *_climb __attribute__((unused)), float *_course __attribute__((unused)), float *_heading __attribute__((unused)), float *_off_heading __attribute__((unused)), float *_off_distance __attribute__((unused)), float *_off_height __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lat in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TARGET_POS_INFO_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field lon in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TARGET_POS_INFO_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field alt in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_TARGET_POS_INFO_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field speed in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return Ground speed
  */
static inline float pprzlink_get_DL_TARGET_POS_INFO_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field climb in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return Climb speed
  */
static inline float pprzlink_get_DL_TARGET_POS_INFO_climb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field course in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_TARGET_POS_INFO_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field heading in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_TARGET_POS_INFO_heading(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field off_heading in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return Offset heading
  */
static inline float pprzlink_get_DL_TARGET_POS_INFO_off_heading(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field off_distance in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return Offset distance
  */
static inline float pprzlink_get_DL_TARGET_POS_INFO_off_distance(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field off_height in message TARGET_POS_INFO
  *
  * @param _payload : a pointer to the TARGET_POS_INFO message
  * @return Offset height
  */
static inline float pprzlink_get_DL_TARGET_POS_INFO_off_height(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/* Compatibility macros */
#define DL_TARGET_POS_INFO_lat(_payload) pprzlink_get_DL_TARGET_POS_INFO_lat(_payload)
#define DL_TARGET_POS_INFO_lon(_payload) pprzlink_get_DL_TARGET_POS_INFO_lon(_payload)
#define DL_TARGET_POS_INFO_alt(_payload) pprzlink_get_DL_TARGET_POS_INFO_alt(_payload)
#define DL_TARGET_POS_INFO_speed(_payload) pprzlink_get_DL_TARGET_POS_INFO_speed(_payload)
#define DL_TARGET_POS_INFO_climb(_payload) pprzlink_get_DL_TARGET_POS_INFO_climb(_payload)
#define DL_TARGET_POS_INFO_course(_payload) pprzlink_get_DL_TARGET_POS_INFO_course(_payload)
#define DL_TARGET_POS_INFO_heading(_payload) pprzlink_get_DL_TARGET_POS_INFO_heading(_payload)
#define DL_TARGET_POS_INFO_off_heading(_payload) pprzlink_get_DL_TARGET_POS_INFO_off_heading(_payload)
#define DL_TARGET_POS_INFO_off_distance(_payload) pprzlink_get_DL_TARGET_POS_INFO_off_distance(_payload)
#define DL_TARGET_POS_INFO_off_height(_payload) pprzlink_get_DL_TARGET_POS_INFO_off_height(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_TARGET_POS_INFO_H_

