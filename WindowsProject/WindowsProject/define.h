#pragma once

#define Single(type) static type* GetInst() { static type mgr; return &mgr; }
