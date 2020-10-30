// MESSAGE SETPOINT_MOTOR support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief SETPOINT_MOTOR message
 *
 * Control Motors directly
 */
struct SETPOINT_MOTOR : mavlink::Message {
    static constexpr msgid_t MSG_ID = 229;
    static constexpr size_t LENGTH = 40;
    static constexpr size_t MIN_LENGTH = 40;
    static constexpr uint8_t CRC_EXTRA = 164;
    static constexpr auto NAME = "SETPOINT_MOTOR";


    uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. */
    std::array<float, 8> setpoint; /*<  Motor throttle in range [-1..1] */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_usec: " << time_usec << std::endl;
        ss << "  setpoint: [" << to_string(setpoint) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_usec;                     // offset: 0
        map << setpoint;                      // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_usec;                     // offset: 0
        map >> setpoint;                      // offset: 8
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
