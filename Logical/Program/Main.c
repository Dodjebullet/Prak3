
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
Speed=500;
}
BOOL up=0;
BOOL down=0;
void _CYCLIC ProgramCyclic(void)
{
	STATE=ETAD & 0x6f;
	if(RUN || Onlinerun){
		switch(STATE){
			case 64:
				CMDD=6;
				break;
			case 33:
				CMDD=15;
				break;
		}
	}
	else{
		CMDD=6;
	}
	if(speedUp==1 && up==0){
		Speed+=50;
		up=1;
	}
	if(speedUp==0){up=0;}
	
	if(speedDown==1 && down==0){
		Speed-=50;
		down=1;
	}
	if(speedDown==0){down=0;}
	if(OTR>8){
		while(Reset==0){
			RUN=0;
			Onlinerun=0;
		}
	}}

void _EXIT ProgramExit(void)
{

}

