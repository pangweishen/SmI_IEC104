/*
 *  control.h
 *
 *  Copyright 2013 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include "model.h"
#include "mms_server_connection.h"

#include "libiec61850_platform_includes.h"
#include "mms_domain.h"
#include "mms_device.h"

#include "iec61850_server.h"

typedef struct sControlObject ControlObject;

ControlObject*
ControlObject_create(MmsServer* mmsServer, MmsDomain* domain, char* lnName, char* name);

void
ControlObject_destroy(ControlObject* self);

void
ControlObject_setOper(ControlObject* self, MmsValue* oper);

void
ControlObject_setCancel(ControlObject* self, MmsValue* cancel);

void
ControlObject_setSBO(ControlObject* self, MmsValue* sbo);

void
ControlObject_setSBOw(ControlObject* self, MmsValue* sbow);

void
ControlObject_setMmsValue(ControlObject* self, MmsValue* value);

MmsValue*
ControlObject_getMmsValue(ControlObject* self);

MmsValue*
ControlObject_getOper(ControlObject* self);

MmsValue*
ControlObject_getSBOw(ControlObject* self);

MmsValue*
ControlObject_getSBO(ControlObject* self);

MmsValue*
ControlObject_getCancel(ControlObject* self);

void
ControlObject_setCtlVal(ControlObject* self, MmsValue* ctlVal);

char*
ControlObject_getName(ControlObject* self);

char*
ControlObject_getLNName(ControlObject* self);

MmsDomain*
ControlObject_getDomain(ControlObject* self);

bool
ControlObject_select(ControlObject* self);

bool
ControlObject_operate(ControlObject* self, MmsValue* value);

bool
ControlObject_installListener(ControlObject* self, ControlHandler listener, void* parameter);

#endif /* CONTROL_H_ */
