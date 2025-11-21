#ifndef _LINUX_UNISTD_H_
#define _LINUX_UNISTD_H_


/*
 * Include machine specific syscallX macros
 */
#include <asm/unistd.h>
#include <sys/syscall.h>
#include <unistd.h>
         

#undef _syscall0
#undef _syscall1
#undef _syscall2
#undef _syscall3
#undef _syscall4
#undef _syscall5
#undef _syscall6


#define _syscall0(type,name) \
type name(void) \
{\
	return syscall(__NR_##name);\
}

#define _syscall1(type,name,type1,arg1) \
type name(type1 arg1) \
{\
	return syscall(__NR_##name, arg1);\
}

#define _syscall2(type,name,type1,arg1,type2,arg2) \
type name(type1 arg1,type2 arg2) \
{\
	return syscall(__NR_##name, arg1, arg2);\
}

#define _syscall3(type,name,type1,arg1,type2,arg2,type3,arg3) \
type name(type1 arg1,type2 arg2,type3 arg3) \
{\
	return syscall(__NR_##name, arg1, arg2, arg3);\
}

#define _syscall4(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4) \
type name (type1 arg1, type2 arg2, type3 arg3, type4 arg4) \
{\
	return syscall(__NR_##name, arg1, arg2, arg3, arg4);\
}

#define _syscall5(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4, \
	  type5,arg5) \
type name (type1 arg1,type2 arg2,type3 arg3,type4 arg4,type5 arg5) \
{\
	return syscall(__NR_##name, arg1, arg2, arg3, arg4, arg5);\
}


#define _syscall6(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4, \
	  type5,arg5,type6,arg6) \
type name (type1 arg1,type2 arg2,type3 arg3,type4 arg4,type5 arg5,type6 arg6) \
{\
	return syscall(__NR_##name, arg1, arg2, arg3, arg4, arg5, arg6);\
}


#endif /* _LINUX_UNISTD_H_ */
