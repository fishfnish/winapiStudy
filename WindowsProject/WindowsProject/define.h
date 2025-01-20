#pragma once

#define SINGLE(type) public:                \
    static type* GetInst()                  \
    {                                       \
        static type mgr;                    \
        return &mgr;                        \
    }                                       \
    private:                                \
        type();                             \
        ~type();                            \

#define fDT TimeMgr::GetInst()->GetfDT()
#define DT TimeMgr::GetInst()->GetDT()