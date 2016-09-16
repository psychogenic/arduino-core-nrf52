/*
  Copyright (c) 2016 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
*/

#ifndef __BLE_MANAGER_H
#define __BLE_MANAGER_H

#include "Arduino.h"
#include "ble.h"
#include "GAP/BLEPeripheral.h"
#include "GATT/BLETypedCharacteristic.cpp"

class BLEPeripheral;

class BLEManagerClass  {
public:
	BLEManagerClass();

    static bool registerPeripheral(BLEPeripheral *peripheral);
	
    static void processBleEvents(ble_evt_t *bleEvent);
	
    static void defaultSerialErrorHandler(char *file, uint32_t errCode, char *msg);
    
	void setErrorHandler(void (*errorHandlerCallback)(char *file, uint32_t errCode, char *msg));
    
private:
    static BLEPeripheral    *_peripheralList[1];
};

extern BLEManagerClass BLEManager;

#endif
