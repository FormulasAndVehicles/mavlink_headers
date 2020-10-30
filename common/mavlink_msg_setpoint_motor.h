#pragma once
// MESSAGE SETPOINT_MOTOR PACKING

#define MAVLINK_MSG_ID_SETPOINT_MOTOR 229


typedef struct __mavlink_setpoint_motor_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float setpoint[8]; /*<  Motor throttle in range [-1..1]*/
} mavlink_setpoint_motor_t;

#define MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN 40
#define MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN 40
#define MAVLINK_MSG_ID_229_LEN 40
#define MAVLINK_MSG_ID_229_MIN_LEN 40

#define MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC 164
#define MAVLINK_MSG_ID_229_CRC 164

#define MAVLINK_MSG_SETPOINT_MOTOR_FIELD_SETPOINT_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SETPOINT_MOTOR { \
    229, \
    "SETPOINT_MOTOR", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_setpoint_motor_t, time_usec) }, \
         { "setpoint", NULL, MAVLINK_TYPE_FLOAT, 8, 8, offsetof(mavlink_setpoint_motor_t, setpoint) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SETPOINT_MOTOR { \
    "SETPOINT_MOTOR", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_setpoint_motor_t, time_usec) }, \
         { "setpoint", NULL, MAVLINK_TYPE_FLOAT, 8, 8, offsetof(mavlink_setpoint_motor_t, setpoint) }, \
         } \
}
#endif

/**
 * @brief Pack a setpoint_motor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param setpoint  Motor throttle in range [-1..1]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setpoint_motor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, setpoint, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN);
#else
    mavlink_setpoint_motor_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.setpoint, setpoint, sizeof(float)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETPOINT_MOTOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC);
}

/**
 * @brief Pack a setpoint_motor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param setpoint  Motor throttle in range [-1..1]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setpoint_motor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, setpoint, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN);
#else
    mavlink_setpoint_motor_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.setpoint, setpoint, sizeof(float)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETPOINT_MOTOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC);
}

/**
 * @brief Encode a setpoint_motor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param setpoint_motor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setpoint_motor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_setpoint_motor_t* setpoint_motor)
{
    return mavlink_msg_setpoint_motor_pack(system_id, component_id, msg, setpoint_motor->time_usec, setpoint_motor->setpoint);
}

/**
 * @brief Encode a setpoint_motor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param setpoint_motor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setpoint_motor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_setpoint_motor_t* setpoint_motor)
{
    return mavlink_msg_setpoint_motor_pack_chan(system_id, component_id, chan, msg, setpoint_motor->time_usec, setpoint_motor->setpoint);
}

/**
 * @brief Send a setpoint_motor message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param setpoint  Motor throttle in range [-1..1]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_setpoint_motor_send(mavlink_channel_t chan, uint64_t time_usec, const float *setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, setpoint, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETPOINT_MOTOR, buf, MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC);
#else
    mavlink_setpoint_motor_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.setpoint, setpoint, sizeof(float)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETPOINT_MOTOR, (const char *)&packet, MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC);
#endif
}

/**
 * @brief Send a setpoint_motor message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_setpoint_motor_send_struct(mavlink_channel_t chan, const mavlink_setpoint_motor_t* setpoint_motor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_setpoint_motor_send(chan, setpoint_motor->time_usec, setpoint_motor->setpoint);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETPOINT_MOTOR, (const char *)setpoint_motor, MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_setpoint_motor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, setpoint, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETPOINT_MOTOR, buf, MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC);
#else
    mavlink_setpoint_motor_t *packet = (mavlink_setpoint_motor_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->setpoint, setpoint, sizeof(float)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETPOINT_MOTOR, (const char *)packet, MAVLINK_MSG_ID_SETPOINT_MOTOR_MIN_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN, MAVLINK_MSG_ID_SETPOINT_MOTOR_CRC);
#endif
}
#endif

#endif

// MESSAGE SETPOINT_MOTOR UNPACKING


/**
 * @brief Get field time_usec from setpoint_motor message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_setpoint_motor_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field setpoint from setpoint_motor message
 *
 * @return  Motor throttle in range [-1..1]
 */
static inline uint16_t mavlink_msg_setpoint_motor_get_setpoint(const mavlink_message_t* msg, float *setpoint)
{
    return _MAV_RETURN_float_array(msg, setpoint, 8,  8);
}

/**
 * @brief Decode a setpoint_motor message into a struct
 *
 * @param msg The message to decode
 * @param setpoint_motor C-struct to decode the message contents into
 */
static inline void mavlink_msg_setpoint_motor_decode(const mavlink_message_t* msg, mavlink_setpoint_motor_t* setpoint_motor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    setpoint_motor->time_usec = mavlink_msg_setpoint_motor_get_time_usec(msg);
    mavlink_msg_setpoint_motor_get_setpoint(msg, setpoint_motor->setpoint);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN? msg->len : MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN;
        memset(setpoint_motor, 0, MAVLINK_MSG_ID_SETPOINT_MOTOR_LEN);
    memcpy(setpoint_motor, _MAV_PAYLOAD(msg), len);
#endif
}
