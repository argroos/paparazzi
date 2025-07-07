/** @file
 *  @brief PPRZLink message header for HITL_GPS in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_HITL_GPS_H_
#define _VAR_MESSAGES_datalink_HITL_GPS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HITL_GPS 71
#define PPRZ_MSG_ID_HITL_GPS 71

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HITL_GPS _send_msg(HITL_GPS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HITL_GPS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lat 
 * @param _lon 
 * @param _alt ellipsoid alt
 * @param _hmsl geoid alt
 * @param _ecef_vel_x 
 * @param _ecef_vel_y 
 * @param _ecef_vel_z 
 * @param _time 
 * @param _fix 
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_HITL_GPS(struct pprzlink_msg * msg, float *_lat, float *_lon, float *_alt, float *_hmsl, float *_ecef_vel_x, float *_ecef_vel_y, float *_ecef_vel_z, float *_time, uint8_t *_fix, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HITL_GPS, "HITL_GPS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _hmsl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ecef_vel_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ecef_vel_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ecef_vel_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _time, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _fix, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HITL_GPS pprz_msg_send_HITL_GPS
#define DOWNLINK_SEND_HITL_GPS(_trans, _dev, lat, lon, alt, hmsl, ecef_vel_x, ecef_vel_y, ecef_vel_z, time, fix, ac_id) pprz_msg_send_HITL_GPS(&((_trans).trans_tx), &((_dev).device), AC_ID, lat, lon, alt, hmsl, ecef_vel_x, ecef_vel_y, ecef_vel_z, time, fix, ac_id)
/**
 * Sends a HITL_GPS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lat 
 * @param _lon 
 * @param _alt ellipsoid alt
 * @param _hmsl geoid alt
 * @param _ecef_vel_x 
 * @param _ecef_vel_y 
 * @param _ecef_vel_z 
 * @param _time 
 * @param _fix 
 * @param _ac_id 
 */
static inline void pprz_msg_send_HITL_GPS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_lat, float *_lon, float *_alt, float *_hmsl, float *_ecef_vel_x, float *_ecef_vel_y, float *_ecef_vel_z, float *_time, uint8_t *_fix, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HITL_GPS(&msg,_lat,_lon,_alt,_hmsl,_ecef_vel_x,_ecef_vel_y,_ecef_vel_z,_time,_fix,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HITL_GPS(_trans, _dev, lat, lon, alt, hmsl, ecef_vel_x, ecef_vel_y, ecef_vel_z, time, fix, ac_id) {}
static inline void pprz_send_msg_HITL_GPS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_lat __attribute__((unused)), float *_lon __attribute__((unused)), float *_alt __attribute__((unused)), float *_hmsl __attribute__((unused)), float *_ecef_vel_x __attribute__((unused)), float *_ecef_vel_y __attribute__((unused)), float *_ecef_vel_z __attribute__((unused)), float *_time __attribute__((unused)), uint8_t *_fix __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lat in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_GPS_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field lon in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_GPS_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field alt in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return ellipsoid alt
  */
static inline float pprzlink_get_DL_HITL_GPS_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field hmsl in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return geoid alt
  */
static inline float pprzlink_get_DL_HITL_GPS_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field ecef_vel_x in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_GPS_ecef_vel_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field ecef_vel_y in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_GPS_ecef_vel_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field ecef_vel_z in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_GPS_ecef_vel_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field time in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline float pprzlink_get_DL_HITL_GPS_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field fix in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_GPS_fix(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 36);
}


/** Getter for field ac_id in message HITL_GPS
  *
  * @param _payload : a pointer to the HITL_GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_GPS_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 37);
}


/* Compatibility macros */
#define DL_HITL_GPS_lat(_payload) pprzlink_get_DL_HITL_GPS_lat(_payload)
#define DL_HITL_GPS_lon(_payload) pprzlink_get_DL_HITL_GPS_lon(_payload)
#define DL_HITL_GPS_alt(_payload) pprzlink_get_DL_HITL_GPS_alt(_payload)
#define DL_HITL_GPS_hmsl(_payload) pprzlink_get_DL_HITL_GPS_hmsl(_payload)
#define DL_HITL_GPS_ecef_vel_x(_payload) pprzlink_get_DL_HITL_GPS_ecef_vel_x(_payload)
#define DL_HITL_GPS_ecef_vel_y(_payload) pprzlink_get_DL_HITL_GPS_ecef_vel_y(_payload)
#define DL_HITL_GPS_ecef_vel_z(_payload) pprzlink_get_DL_HITL_GPS_ecef_vel_z(_payload)
#define DL_HITL_GPS_time(_payload) pprzlink_get_DL_HITL_GPS_time(_payload)
#define DL_HITL_GPS_fix(_payload) pprzlink_get_DL_HITL_GPS_fix(_payload)
#define DL_HITL_GPS_ac_id(_payload) pprzlink_get_DL_HITL_GPS_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_HITL_GPS_H_

