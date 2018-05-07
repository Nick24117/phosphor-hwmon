#pragma once

#include "types.hpp"
#include "sensorset.hpp"
#include "hwmonio.hpp"

namespace sensor
{

/** @class Sensor
 *  @brief Sensor object based on a SensorSet container's key type
 *  @details Sensor object to create and modify an associated device's sensor
 *  attributes based on the key type of each sensor in the set provided by the
 *  device.
 */
class Sensor
{
    public:
        Sensor() = delete;
        Sensor(const Sensor&) = delete;
        Sensor(Sensor&&) = default;
        Sensor& operator=(const Sensor&) = delete;
        Sensor& operator=(Sensor&&) = default;
        ~Sensor() = default;

        /**
         * @brief Constructs Sensor object
         *
         * @param[in] sensor - A pair of sensor indentifiers
         */
        explicit Sensor(const SensorSet::key_type& sensor);

    private:
        /** @brief Sensor object's identifiers */
        SensorSet::key_type sensor;
};

/**
 * @brief Add status interface and functional property for sensor
 * @details When a sensor has an associated fault file, the OperationalStatus
 * interface is added along with setting the Functional property to the
 * corresponding value found in the fault file.
 *
 * @param[in] sensor - Sensor identification data
 * @param[in] ioAccess - I/O access to sysfs
 * @param[in] devPath - Device path
 * @param[in] info - Sensor object information
 *
 * @return - Shared pointer to the status object
 */
std::shared_ptr<StatusObject> addStatus(
        const SensorSet::key_type& sensor,
        const hwmonio::HwmonIO& ioAccess,
        const std::string& devPath,
        ObjectInfo& info);

} // namespace sensor
