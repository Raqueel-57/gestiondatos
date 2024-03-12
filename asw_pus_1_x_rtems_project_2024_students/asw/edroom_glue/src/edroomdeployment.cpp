//##############################################################################
//###############     This file has been generated by EDROOM     ###############
//##############################################################################
 
 
#include <edroom_glue/edroomdeployment.h>
 
//*****************************************************************************
//Main Wait
 
void MainWait(ICUASW   &comp1,
					CCEPDManager   &comp2,
					CCTM_ChannelCtrl   &comp3){
 
	Pr_Time waitTime(3, 0);
 
#ifdef _EDROOM_SYSTEM_CLOSE
	while(!comp1.EDROOMIsComponentFinished()
				||!comp2.EDROOMIsComponentFinished()
				||!comp3.EDROOMIsComponentFinished())
#else
	while(true)
#endif

 
		Pr_DelayIn(waitTime);
}
 
//*****************************************************************************
//SetMemory
 
void CEDROOMSystemMemory::SetMemory(){
 
	comp1Memory.SetMemory(10, comp1Messages, &comp1MessagesMarks[0]
					,13,comp1QueueNodes, &comp1QueueNodesMarks[0]);
	comp2Memory.SetMemory(10, comp2Messages, &comp2MessagesMarks[0]
					,11,comp2QueueNodes, &comp2QueueNodesMarks[0]);
	comp3Memory.SetMemory(10, comp3Messages, &comp3MessagesMarks[0]
					,10,comp3QueueNodes, &comp3QueueNodesMarks[0]);
}
 
//*****************************************************************************
//SetComponents
 
void CEDROOMSystemCommSAP::SetComponents(ICUASW   *p_comp1,
										CCEPDManager   *p_comp2,
										CCTM_ChannelCtrl   *p_comp3){
	mp_comp1=p_comp1;
	mp_comp2=p_comp2;
	mp_comp3=p_comp3;
}
 
 
//*****************************************************************************
//*****************************************************************************
//Signal Translation Functions
//*****************************************************************************
//*****************************************************************************
 
 
TEDROOMSignal CEDROOMSystemCommSAP::C2EPDManager_PTMChannelCtrl__C3TM_ChannelCtrl_PTMChannelCtrl(TEDROOMSignal signalOut){
 
	TEDROOMSignal signalIn;
 
	switch(signalOut){
 
		case( CCEPDManager::STxTM):	 signalIn=CCTM_ChannelCtrl::STxTM; break;
 
		default: signalIn=(TEDROOMSignal)(-1); break;
 
	}
	return signalIn;
 
}
 
TEDROOMSignal CEDROOMSystemCommSAP::C3TM_ChannelCtrl_PTMChannelCtrl__C2EPDManager_PTMChannelCtrl(TEDROOMSignal signalOut){
 
	TEDROOMSignal signalIn;
 
	switch(signalOut){
 
		case( CCTM_ChannelCtrl::STMQueued):	 signalIn=CCEPDManager::STMQueued; break;
 
		default: signalIn=(TEDROOMSignal)(-1); break;
 
	}
	return signalIn;
 
}
 
 
 
//*****************************************************************************
//RegisterInterfaces
 
void CEDROOMSystemCommSAP::RegisterInterfaces(){
 
	// Register Interface for Component 1
	m_localCommSAP.RegisterInterface(1, mp_comp1->Timer, mp_comp1);
 
	// Register Interface for Component 2
	m_localCommSAP.RegisterInterface(1, mp_comp2->RxTC, mp_comp2);
	m_localCommSAP.RegisterInterface(2, mp_comp2->TMChannelCtrl, mp_comp2);
 
	// Register Interface for Component 3
	m_localCommSAP.RegisterInterface(1, mp_comp3->TMChannelCtrl, mp_comp3);
 
}
 
 
//*****************************************************************************
////SetLocalConnections
 
void CEDROOMSystemCommSAP::SetLocalConnections(){
 
	m_localCommSAP.Connect(mp_comp2->TMChannelCtrl, mp_comp3->TMChannelCtrl, connections[0], 
					C2EPDManager_PTMChannelCtrl__C3TM_ChannelCtrl_PTMChannelCtrl, 
					C3TM_ChannelCtrl_PTMChannelCtrl__C2EPDManager_PTMChannelCtrl);
 
}
 
 
//*****************************************************************************
////SetRemoteConnections
 
void CEDROOMSystemCommSAP::SetRemoteConnections(){
 
}
 
//*****************************************************************************
////SetConnections
 
void CEDROOMSystemCommSAP::SetConnections(){
 
	SetLocalConnections();
	SetRemoteConnections();
 
}
 
//*****************************************************************************
////CEDROOMSystemDeployment Constructor
 
CEDROOMSystemDeployment::CEDROOMSystemDeployment(){
 
#ifdef CONFIG_EDROOMSL_ADD_TRACE
#endif
	systemMemory.SetMemory();
 
}
 
//*****************************************************************************
////Config
 
void CEDROOMSystemDeployment::Config(ICUASW   *p_comp1,
											CCEPDManager   *p_comp2,
											CCTM_ChannelCtrl   *p_comp3){
 
	mp_comp1=p_comp1;
	mp_comp2=p_comp2;
	mp_comp3=p_comp3;
 
	systemCommSAP.SetComponents(	p_comp1,
									p_comp2,
									p_comp3);
 
	systemCommSAP.RegisterInterfaces();
	systemCommSAP.SetConnections();
 
}
 
//*****************************************************************************
////StartComponents
 
void CEDROOMSystemDeployment::StartComponents(){
	mp_comp1->EDROOMStart();
	mp_comp2->EDROOMStart();
	mp_comp3->EDROOMStart();
 
}
 
//*****************************************************************************
////Start
 
void CEDROOMSystemDeployment::Start(){
 
#ifdef CONFIG_EDROOMBP_DEPLOYMENT_NEED_TASK
 
	Pr_Task MainTask(CEDROOMSystemDeployment::main_task,EDROOMprioMINIMUM,1024*16);
 
	kernel.Start();
 
#else
 
StartComponents();
 
	kernel.Start();
 
	MainWait(*mp_comp1,
				*mp_comp2,
				*mp_comp3);
 
 
#endif
 
}
 
#ifdef CONFIG_EDROOMBP_DEPLOYMENT_NEED_TASK
 
	extern CEDROOMSystemDeployment systemDeployment;
 
 
//*****************************************************************************
////main_task
 
 
Pr_TaskRV_t CEDROOMSystemDeployment::main_task(Pr_TaskP_t){
 
	systemDeployment.StartComponents();
	MainWait(*systemDeployment.mp_comp1,
				*systemDeployment.mp_comp2,
				*systemDeployment.mp_comp3);
 
}
#endif
