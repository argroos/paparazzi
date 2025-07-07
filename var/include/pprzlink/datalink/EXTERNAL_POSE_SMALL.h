/** @file
 *  @brief PPRZLink message header for EXTERNAL_POSE_SMALL in class datalink
 *
 *  
        Position, speed and orientation in local frame from a remote vision system
        Smaller message where position, speed is in cm multiplied by a resolution
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_EXTERNAL_POSE_SMALL_H_
#define _VAR_MESSAGES_datalink_EXTERNAL_POSE_SMALL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_EXTERNAL_POSE_SMALL 55
#define PPRZ_MSG_ID_EXTERNAL_POSE_SMALL 55

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_EXTERNAL_POSE_SMALL _send_msg(EXTERNAL_POSE_SMALL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a EXTERNAL_POSE_SMALL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id AC id for which the data is meant
 * @param _timestamp Timestamp from the measurement
 * @param _enu_pos ENU position in vision frame(bits 31-21 east position [cm*pos_res] : bits 20-10 north position [cm*pos_res] : bits 9-0 up position [cm*pos_res])
 * @param _enu_speed ENU speed in vision frame(bits 31-21 east position [cm*pos_res] : bits 20-10 north position [cm*pos_res] : bits 9-0 up position [cm*pos_res])
 * @param _heading Heading in ENU vision frame
 */
static inline void pprzlink_msg_v2_send_EXTERNAL_POSE_SMALL(struct pprzlink_msg * msg, uint8_t *_ac_id, uint32_t *_timestamp, uint32_t *_enu_pos, uint32_t *_enu_speed, int16_t *_heading) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_EXTERNAL_POSE_SMALL, "EXTERNAL_POSE_SMALL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _timestamp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _enu_pos, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _enu_speed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _heading, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_EXTERNAL_POSE_SMALL pprz_msg_send_EXTERNAL_POSE_SMALL
#define DOWNLINK_SEND_EXTERNAL_POSE_SMALL(_trans, _dev, ac_id, timestamp, enu_pos, enu_speed, heading) pprz_msg_send_EXTERNAL_POSE_SMALL(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, timestamp, enu_pos, enu_speed, heading)
/**
 * Sends a EXTERNAL_POSE_SMALL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id AC id for which the data is meant
 * @param _timestamp Timestamp from the measurement
 * @param _enu_pos ENU position in vision frame(bits 31-21 east position [cm*pos_res] : bits 20-10 north position [cm*pos_res] : bits 9-0 up position [cm*pos_res])
 * @param _enu_speed ENU speed in vision frame(bits 31-21 east position [cm*pos_res] : bits 20-10 north position [cm*pos_res] : bits 9-0 up position [cm*pos_res])
 * @param _heading Heading in ENU vision frame
 */
static inline void pprz_msg_send_EXTERNAL_POSE_SMALL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint32_t *_timestamp, uint32_t *_enu_pos, uint32_t *_enu_speed, int16_t *_heading) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_EXTERNAL_POSE_SMALL(&msg,_ac_id,_timestamp,_enu_pos,_enu_speed,_heading);
}


#else // DOWNLINK

#define DOWNLINK_SEND_EXTERNAL_POSE_SMALL(_trans, _dev, ac_id, timestamp, enu_pos, enu_speed, heading) {}
static inline void pprz_send_msg_EXTERNAL_POSE_SMALL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint32_t *_timestamp __attribute__((unused)), uint32_t *_enu_pos __attribute__((unused)), uint32_t *_enu_speed __attribute__((unused)), int16_t *_heading __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message EXTERNAL_POSE_SMALL
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_SMALL message
  * @return AC id for which the data is meant
  */
static inline uint8_t pprzlink_get_DL_EXTERNAL_POSE_SMALL_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field timestamp in message EXTERNAL_POSE_SMALL
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_SMALL message
  * @return Timestamp from the measurement
  */
static inline uint32_t pprzlink_get_DL_EXTERNAL_POSE_SMALL_timestamp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 5);
}


/** Getter for field enu_pos in message EXTERNAL_POSE_SMALL
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_SMALL message
  * @return ENU position in vision frame(bits 31-21 east position [cm*pos_res] : bits 20-10 north position [cm*pos_res] : bits 9-0 up position [cm*pos_res])
  */
static inline uint32_t pprzlink_get_DL_EXTERNAL_POSE_SMALL_enu_pos(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 9);
}


/** Getter for field enu_speed in message EXTERNAL_POSE_SMALL
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_SMALL message
  * @return ENU speed in vision frame(bits 31-21 east position [cm*pos_res] : bits 20-10 north position [cm*pos_res] : bits 9-0 up position [cm*pos_res])
  */
static inline uint32_t pprzlink_get_DL_EXTERNAL_POSE_SMALL_enu_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 13);
}


/** Getter for field heading in message EXTERNAL_POSE_SMALL
  *
  * @param _payload : a pointer to the EXTERNAL_POSE_SMALL message
  * @return Heading in ENU vision frame
  */
static inline int16_t pprzlink_get_DL_EXTERNAL_POSE_SMALL_heading(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 17);
}


/* Compatibility macros */
#define DL_EXTERNAL_POSE_SMALL_ac_id(_payload) pprzlink_get_DL_EXTERNAL_POSE_SMALL_ac_id(_payload)
#define DL_EXTERNAL_POSE_SMALL_timestamp(_payload) pprzlink_get_DL_EXTERNAL_POSE_SMALL_timestamp(_payload)
#define DL_EXTERNAL_POSE_SMALL_enu_pos(_payload) pprzlink_get_DL_EXTERNAL_POSE_SMALL_enu_pos(_payload)
#define DL_EXTERNAL_POSE_SMALL_enu_speed(_payload) pprzlink_get_DL_EXTERNAL_POSE_SMALL_enu_speed(_payload)
#define DL_EXTERNAL_POSE_SMALL_heading(_payload) pprzlink_get_DL_EXTERNAL_POSE_SMALL_heading(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_EXTERNAL_POSE_SMALL_H_

