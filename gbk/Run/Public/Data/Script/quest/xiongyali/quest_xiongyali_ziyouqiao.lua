--自由桥

--MisDescBegin
x213007_g_ScriptId = 213007
x213007_g_MissionIdPre =151
x213007_g_MissionId = 152
x213007_g_MissionKind = 24
x213007_g_MissionLevel = 125
x213007_g_ScriptIdNext = {ScriptId = 213008 ,LV = 1 }
x213007_g_Name	="拔都" 
x213007_g_DemandItem ={}
x213007_g_DemandKill ={{id=393,num=15}}

x213007_g_MissionName="自由桥"
x213007_g_MissionInfo="    伊丽莎白桥上的抵抗已经逐渐微弱。南边自由桥附近有一些匈牙利弩手在抵抗，我不能让我的战士在敌人的箭雨下冲锋。勇士，你去帮我解决掉15个#R匈牙利弩手#W，扫清我们的道路。"  --任务描述
x213007_g_MissionTarget="    帮助#G拔都#W杀死15名#R匈牙利弩手#W。"		                                                                                               
x213007_g_MissionComplete="    做的好，我可以让我的战士冲锋了。"					--完成任务npc说话的话
x213007_g_ContinueInfo="    如果贸然冲锋的话，那些弩手会给我们造成大量伤亡。"
--任务奖励
x213007_g_MoneyBonus = 10000
--固定物品奖励，最多8种
x213007_g_ItemBonus={}

--可选物品奖励，最多8种
x213007_g_RadioItemBonus={}

--MisDescEnd
x213007_g_ExpBonus = 1000
--**********************************

--任务入口函数

--**********************************

function x213007_OnDefaultEvent(sceneId, selfId, targetId)	--点击该任务后执行此脚本

	--检测列出条件
	if x213007_CheckPushList(sceneId, selfId, targetId) <= 0 then
		return
	end

	--如果已接此任务
	if IsHaveMission(sceneId,selfId, x213007_g_MissionId) > 0 then
	misIndex = GetMissionIndexByID(sceneId,selfId,x213007_g_MissionId)
		if x213007_CheckSubmit(sceneId, selfId, targetId) <= 0 then
                        BeginEvent(sceneId)
			AddText(sceneId,"#Y"..x213007_g_MissionName)
			AddText(sceneId,x213007_g_ContinueInfo)
		        AddText(sceneId,"#Y任务目标#W") 
			AddText(sceneId,x213007_g_MissionTarget) 
			AddText(sceneId,format("\n    杀死匈牙利弩手   %d/%d", GetMissionParam(sceneId,selfId,misIndex,0),x213007_g_DemandKill[1].num ))
			EndEvent()
			DispatchEventList(sceneId, selfId, targetId)
		end

		     
                if x213007_CheckSubmit(sceneId, selfId, targetId) > 0 then
                     BeginEvent(sceneId)
                     AddText(sceneId,"#Y"..x213007_g_MissionName)
		     AddText(sceneId,x213007_g_MissionComplete)
		     AddMoneyBonus(sceneId, x213007_g_MoneyBonus)
		     EndEvent()
                     DispatchMissionContinueInfo(sceneId, selfId, targetId, x213007_g_ScriptId, x213007_g_MissionId)
                end

        elseif x213007_CheckAccept(sceneId, selfId, targetId) > 0 then
	    	
		--发送任务接受时显示的信息
		BeginEvent(sceneId)
		AddText(sceneId,"#Y"..x213007_g_MissionName)
                AddText(sceneId,x213007_g_MissionInfo) 
		AddText(sceneId,"#Y任务目标#W") 
		AddText(sceneId,x213007_g_MissionTarget) 
		AddMoneyBonus(sceneId, x213007_g_MoneyBonus)	
		EndEvent()
		
		DispatchMissionInfo(sceneId, selfId, targetId, x213007_g_ScriptId, x213007_g_MissionId)
        end
	
end



--**********************************

--列举事件

--**********************************

function x213007_OnEnumerate(sceneId, selfId, targetId)


	--如果玩家完成过这个任务
	if IsMissionHaveDone(sceneId, selfId, x213007_g_MissionId) > 0 then
		return 
	end
	--如果已接此任务
	if  x213007_CheckPushList(sceneId, selfId, targetId) > 0 then
		AddNumText(sceneId, x213007_g_ScriptId, x213007_g_MissionName)
	end
	
end



--**********************************

--检测接受条件

--**********************************

function x213007_CheckAccept(sceneId, selfId, targetId)

	if (GetName(sceneId,targetId)==x213007_g_Name) then 
					return 1
	end
	return 0
end


--**********************************

--检测查看条件

--**********************************

function x213007_CheckPushList(sceneId, selfId, targetId)
	if (sceneId==13) then
		if IsMissionHaveDone(sceneId, selfId, x213007_g_MissionIdPre) > 0 then
        	    	return 1
        	end
        end
        return 0
	
end

--**********************************

--接受

--**********************************

function x213007_OnAccept(sceneId, selfId)

	        BeginEvent(sceneId)
		AddMission( sceneId, selfId, x213007_g_MissionId, x213007_g_ScriptId, 1, 0, 0)
		AddText(sceneId,"接受任务："..x213007_g_MissionName) 
		EndEvent()
		DispatchMissionTips(sceneId, selfId)
		                                               
	     
end



--**********************************

--放弃

--**********************************

function x213007_OnAbandon(sceneId, selfId)

	--删除玩家任务列表中对应的任务
	DelMission(sceneId, selfId, x213007_g_MissionId)
	for i, item in pairs(x213007_g_DemandItem) do
		DelItem(sceneId, selfId, item.id, item.num)
	end

end



--**********************************

--检测是否可以提交

--**********************************

function x213007_CheckSubmit( sceneId, selfId, targetId)
	misIndex = GetMissionIndexByID(sceneId,selfId,x213007_g_MissionId)
	if GetMissionParam(sceneId,selfId,misIndex,0) == x213007_g_DemandKill[1].num then
	        return 1
	end
	return 0

end



--**********************************

--提交

--**********************************

function x213007_OnSubmit(sceneId, selfId, targetId, selectRadioId)

	if DelMission(sceneId, selfId, x213007_g_MissionId) > 0 then
	
		MissionCom(sceneId, selfId, x213007_g_MissionId)
		AddExp(sceneId, selfId, x213007_g_ExpBonus)
		AddMoney(sceneId, selfId, x213007_g_MoneyBonus)
		for i, item in pairs(x213007_g_RadioItemBonus) do
	        if item.id == selectRadioId then
	        item={{selectRadioID, 1}}
	        end
	        end

		for i, item in pairs(x213007_g_DemandItem) do
		DelItem(sceneId, selfId, item.id, item.num)
		end
		CallScriptFunction( x213007_g_ScriptIdNext.ScriptId, "OnDefaultEvent",sceneId, selfId, targetId )
	end
	

	
end



--**********************************

--杀死怪物或玩家

--**********************************

function x213007_OnKillObject(sceneId, selfId, objdataId)
	 if IsHaveMission(sceneId, selfId, x213007_g_MissionId) > 0 then 
	 misIndex = GetMissionIndexByID(sceneId,selfId,x213007_g_MissionId)  
	 num = GetMissionParam(sceneId,selfId,misIndex,0) 
	 	 if objdataId == x213007_g_DemandKill[1].id then 
       		    if num < x213007_g_DemandKill[1].num then
       		    	 SetMissionByIndex(sceneId,selfId,misIndex,0,num+1)
       		         BeginEvent(sceneId)
			 AddText(sceneId,format("杀死匈牙利弩手   %d/%d", GetMissionParam(sceneId,selfId,misIndex,0),x213007_g_DemandKill[1].num )) 
			 EndEvent()
			 DispatchMissionTips(sceneId, selfId)
		    end
       		 end
       		 
      end  

end



--**********************************

--进入区域事件

--**********************************

function x213007_OnEnterArea(sceneId, selfId, zoneId)

end



--**********************************

--道具改变

--**********************************

function x213007_OnItemChanged(sceneId, selfId, itemdataId)

end

