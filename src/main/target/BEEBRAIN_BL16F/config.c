/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "platform.h"

#ifdef USE_TARGET_CONFIG

#include "common/axis.h"
#include "common/maths.h"

#include "config/feature.h"

#include "drivers/light_led.h"
#include "drivers/pwm_esc_detect.h"
#include "drivers/pwm_output.h"

#include "fc/config.h"
#include "fc/controlrate_profile.h"
#include "fc/rc_modes.h"
#include "fc/rc_controls.h"

#include "flight/mixer.h"
#include "flight/pid.h"

#include "rx/rx.h"
#include "rx/cc2500_frsky_common.h"

#include "io/serial.h"
#include "io/osd.h"
#include "io/vtx.h"

#include "sensors/battery.h"
#include "sensors/gyro.h"

#include "telemetry/telemetry.h"

#if defined(BEEBRAIN_BL16FRX)
    // Remove after test
    // T8SG
    #define DEFAULT_TX_BIND_OFFSET          -42
    #define DEFAULT_TX_BIND_ID0             0
    #define DEFAULT_TX_BIND_ID1             191
#endif

void targetConfiguration(void)
{
    osdConfigMutable()->item_pos[OSD_CRAFT_NAME]        = OSD_POS(9, 11)  | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_MAIN_BATT_VOLTAGE] = OSD_POS(23, 10) | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_ITEM_TIMER_2]      = OSD_POS(2, 10)  | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_FLYMODE]           = OSD_POS(17, 10) | VISIBLE_FLAG;
    osdConfigMutable()->item_pos[OSD_VTX_CHANNEL]       = OSD_POS(10, 10) | VISIBLE_FLAG;

    motorConfigMutable()->dev.motorPwmProtocol = PWM_TYPE_DSHOT600;

    vtxSettingsConfigMutable()->band = 5;
    vtxSettingsConfigMutable()->channel = 1;

    modeActivationConditionsMutable(0)->modeId           = BOXANGLE;
    modeActivationConditionsMutable(0)->auxChannelIndex  = AUX2 - NON_AUX_CHANNEL_COUNT;
    modeActivationConditionsMutable(0)->range.startStep  = CHANNEL_VALUE_TO_STEP(900);
    modeActivationConditionsMutable(0)->range.endStep    = CHANNEL_VALUE_TO_STEP(2100);

    modeActivationConditionsMutable(1)->modeId           = BOXARM;
    modeActivationConditionsMutable(1)->auxChannelIndex  = AUX1 - NON_AUX_CHANNEL_COUNT;
    modeActivationConditionsMutable(1)->range.startStep  = CHANNEL_VALUE_TO_STEP(1700);
    modeActivationConditionsMutable(1)->range.endStep    = CHANNEL_VALUE_TO_STEP(2100);

    strcpy(pilotConfigMutable()->name, "BeeBrain");

    #if defined(BEEBRAIN_BL16FRX)
    do {
        uint8_t defaultTXHopTable[50] = {0,30,60,91,120,150,180,210,5,35,65,95,125,155,185,215,10,40,70,100,130,160,190,221,15,45,75,105,135,165,195,225,20,50,80,110,140,170,200,230,25,55,85,115,145,175,205,0,0,0};
        rxFrSkySpiConfigMutable()->bindOffset  = DEFAULT_TX_BIND_OFFSET;
        rxFrSkySpiConfigMutable()->bindTxId[0] = DEFAULT_TX_BIND_ID0;
        rxFrSkySpiConfigMutable()->bindTxId[1] = DEFAULT_TX_BIND_ID1;
        for (uint8_t i = 0; i < 50; i++) {
            rxFrSkySpiConfigMutable()->bindHopData[i] = defaultTXHopTable[i];
        }
    } while (0);
    #endif
}
#endif
