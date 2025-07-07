/** @file
 *  @brief PPRZLink message header for DOUBLET in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DOUBLET_H_
#define _VAR_MESSAGES_telemetry_DOUBLET_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DOUBLET 183
#define PPRZ_MSG_ID_DOUBLET 183

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DOUBLET _send_msg(DOUBLET,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DOUBLET message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _active Doublet is active
 * @param _axis Current doublet axis
 * @param _amplitude Amplitude
 * @param _current_value Current doublet value
 * @param _doublet_mode_3211 Mode 3211 enabled
 */
static inline void pprzlink_msg_v2_send_DOUBLET(struct pprzlink_msg * msg, uint8_t *_active, uint8_t *_axis, int16_t *_amplitude, int16_t *_current_value, uint8_t *_doublet_mode_3211) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+2+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+2+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DOUBLET, "DOUBLET");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _active, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _axis, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _amplitude, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _current_value, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _doublet_mode_3211, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DOUBLET pprz_msg_send_DOUBLET
#define DOWNLINK_SEND_DOUBLET(_trans, _dev, active, axis, amplitude, current_value, doublet_mode_3211) pprz_msg_send_DOUBLET(&((_trans).trans_tx), &((_dev).device), AC_ID, active, axis, amplitude, current_value, doublet_mode_3211)
/**
 * Sends a DOUBLET message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _active Doublet is active
 * @param _axis Current doublet axis
 * @param _amplitude Amplitude
 * @param _current_value Current doublet value
 * @param _doublet_mode_3211 Mode 3211 enabled
 */
static inline void pprz_msg_send_DOUBLET(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_active, uint8_t *_axis, int16_t *_amplitude, int16_t *_current_value, uint8_t *_doublet_mode_3211) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DOUBLET(&msg,_active,_axis,_amplitude,_current_value,_doublet_mode_3211);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DOUBLET(_trans, _dev, active, axis, amplitude, current_value, doublet_mode_3211) {}
static inline void pprz_send_msg_DOUBLET(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_active __attribute__((unused)), uint8_t *_axis __attribute__((unused)), int16_t *_amplitude __attribute__((unused)), int16_t *_current_value __attribute__((unused)), uint8_t *_doublet_mode_3211 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field active in message DOUBLET
  *
  * @param _payload : a pointer to the DOUBLET message
  * @return Doublet is active
  */
static inline uint8_t pprzlink_get_DL_DOUBLET_active(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field axis in message DOUBLET
  *
  * @param _payload : a pointer to the DOUBLET message
  * @return Current doublet axis
  */
static inline uint8_t pprzlink_get_DL_DOUBLET_axis(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field amplitude in message DOUBLET
  *
  * @param _payload : a pointer to the DOUBLET message
  * @return Amplitude
  */
static inline int16_t pprzlink_get_DL_DOUBLET_amplitude(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field current_value in message DOUBLET
  *
  * @param _payload : a pointer to the DOUBLET message
  * @return Current doublet value
  */
static inline int16_t pprzlink_get_DL_DOUBLET_current_value(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field doublet_mode_3211 in message DOUBLET
  *
  * @param _payload : a pointer to the DOUBLET message
  * @return Mode 3211 enabled
  */
static inline uint8_t pprzlink_get_DL_DOUBLET_doublet_mode_3211(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 10);
}


/* Compatibility macros */
#define DL_DOUBLET_active(_payload) pprzlink_get_DL_DOUBLET_active(_payload)
#define DL_DOUBLET_axis(_payload) pprzlink_get_DL_DOUBLET_axis(_payload)
#define DL_DOUBLET_amplitude(_payload) pprzlink_get_DL_DOUBLET_amplitude(_payload)
#define DL_DOUBLET_current_value(_payload) pprzlink_get_DL_DOUBLET_current_value(_payload)
#define DL_DOUBLET_doublet_mode_3211(_payload) pprzlink_get_DL_DOUBLET_doublet_mode_3211(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DOUBLET_H_

