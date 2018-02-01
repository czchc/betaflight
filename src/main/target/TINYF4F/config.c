/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <platform.h>

#ifdef TARGET_CONFIG

#include "common/axis.h"
#include "common/maths.h"

#include "config/feature.h"

#include "drivers/light_led.h"
#include "drivers/pwm_esc_detect.h"

#include "fc/config.h"
#include "fc/controlrate_profile.h"
#include "fc/rc_modes.h"
#include "fc/rc_controls.h"

#include "flight/mixer.h"
#include "flight/pid.h"

#include "rx/rx.h"

#include "io/serial.h"
#include "io/osd.h"

#include "sensors/battery.h"
#include "sensors/gyro.h"

#include "telemetry/telemetry.h"

void targetConfiguration(void)
{
    osdConfigMutable()->item_pos[OSD_CRAFT_NAME]        = OSD_POS(9, 11)  | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_MAIN_BATT_VOLTAGE] = OSD_POS(23, 10) | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ITEM_TIMER_2]      = OSD_POS(2, 10)  | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_FLYMODE]           = OSD_POS(17, 10) | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_VTX_CHANNEL]       = OSD_POS(10, 10) | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_RSSI_VALUE]         &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ITEM_TIMER_1]       &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_THROTTLE_POS]       &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_CROSSHAIRS]         &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_HORIZON_SIDEBARS]   &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ARTIFICIAL_HORIZON] &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_CURRENT_DRAW]       &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_MAH_DRAWN]          &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_GPS_SPEED]          &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_GPS_LON]            &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_GPS_LAT]            &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_GPS_SATS]           &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_HOME_DIR]           &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_HOME_DIST]          &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_COMPASS_BAR]        &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ALTITUDE]           &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ROLL_PIDS]          &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_PITCH_PIDS]         &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_YAW_PIDS]           &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_DEBUG]              &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_POWER]              &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_PIDRATE_PROFILE]    &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_WARNINGS]           &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_AVG_CELL_VOLTAGE]   &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_PITCH_ANGLE]        &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ROLL_ANGLE]         &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_MAIN_BATT_USAGE]    &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_DISARMED]           &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_NUMERICAL_HEADING]  &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_NUMERICAL_VARIO]    &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ESC_TMP]            &= ~VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ESC_RPM]            &= ~VISIBLE_FLAG;
}
#endif
