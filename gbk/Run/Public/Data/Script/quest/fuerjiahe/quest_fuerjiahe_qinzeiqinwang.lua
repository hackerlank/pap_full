--擒贼擒王

--MisDescBegin
x223008_g_ScriptId = 223008
x223008_g_MissionIdPre =299
x223008_g_MissionId = 300
x223008_g_MissionKind = 20
x223008_g_MissionLevel = 100
--x223008_g_ScriptIdNext = {ScriptId = 223007 ,LV = 1 }
x223008_g_Name	="拔都" 
x223008_g_DemandItem ={}
x223008_g_DemandKill ={{id=445,num=20}}

x223008_g_MissionName="擒贼擒王"
x223008_g_MissionInfo="    你做得很好，年轻的（职业），我需要给他们更多的催化剂，让这场战事尽快的结束，打败他们。\n \n    我们要采取一些更有效的计划，但是难度可能会增加很多。你再去敌人的营地，消灭他们的军官！"  --任务描述
x223008_g_MissionTarget="    #G拔都#W命你返回#G钦察营地#W杀死20个#R钦察军官#W。"		                                                                                               
x223008_g_MissionComplete="    他们的军队有些混乱了，这让蒙哥有了可乘之机，你成功了勇士！"					--完成任务npc说话的话
x223008_g_ContinueInfo="    没有了军官的钦察人会丧失了进攻的勇气。"
--任务奖励
x223008_g_MoneyBonus = 500

--固定物品奖励，最多8种
x223008_g_ItemBonus={}

--可选物品奖励，最多8种
x223008_g_RadioItemBonus={}

--MisDescEnd
x223008_g_ExpBonus = 4000
--**********************************

--任务入口函数

--**********************************

function x223008_OnDefaultEvent(sceneId, selfId, targetId)	--点击该任务后执行此脚本

	--检测列出条件
	if x223008_CheckPushList(sceneId, selfId, targetId) <= 0 then
		return
	end

	--如果已接此任务
	if IsHaveMission(sceneId,selfId, x223008_g_MissionId) > 0 then
	misIndex = GetMissionIndexByID(sceneId,selfId,x223008_g_MissionId)
		if x223008_CheckSubmit(sceneId, selfId, targetId) <= 0 then
                        BeginEvent(sceneId)
			AddText(sceneId,"#Y"..x223008_g_MissionName)
			AddText(sceneId,x223008_g_ContinueInfo)
		        AddText(sceneId,"#Y任务目标#W") 
			AddText(sceneId,x223008_g_MissionTarget) 
			AddText(sceneId,format("\n    杀死钦察军官   %d/%d", GetMissionParam(sceneId,selfId,misIndex,0),x223008_g_DemandKill[1].num ))
			EndEvent()
			DispatchEventList(sceneId, selfId, targetId)
		end

		     
                if x223008_CheckSubmit(sceneId, selfId, targetId) > 0 then
                     BeginEvent(sceneId)
                     AddText(sceneId,"#Y"..x223008_g_MissionName)
		     AddText(sceneId,x223008_g_MissionComplete)
		     AddMoneyBonus(sceneId, x223008_g_MoneyBonus)
		     EndEvent()
                     DispatchMissionContinueInfo(sceneId, selfId, targetId, x223008_g_ScriptId, x223008_g_MissionId)
                end

        elseif x223008_CheckAccept(sceneId, selfId, targetId) > 0 then
	    	
		--发送任务接受时显示的信息
		BeginEvent(sceneId)
		AddText(sceneId,"#Y"..x223008_g_MissionName)
                AddText(sceneId,x223008_g_MissionInfo) 
		AddText(sceneId,"#Y任务目标#W") 
		AddText(sceneId,x223008_g_MissionTarget) 
		AddMoneyBonus(sceneId, x223008_g_MoneyBonus)
		EndEvent()
		
		DispatchMissionInfo(sceneId, selfId, targetId, x223008_g_ScriptId, x223008_g_MissionId)
        end
	
end



--**********************************

--列举事件

--**********************************

function x223008_OnEnumerate(sceneId, selfId, targetId)


	--如果玩家完成过这个任务
	if IsMissionHaveDone(sceneId, selfId, x223008_g_MissionId) > 0 then
		return 
	end
	--如果已接此任务
	if  x223008_CheckPushList(sceneId, selfId, targetId) > 0 then
		AddNumText(sceneId, x223008_g_ScriptId, x223008_g_MissionName)
	end
	
end



--**********************************

--检测接受条件

--**********************************

function x223008_CheckAccept(sceneId, selfId, targetId)

	if (GetName(sceneId,targetId)==x223008_g_Name) then 
					return 1
	end
	return 0
end


--**********************************

--检测查看条件

--**********************************

function x223008_CheckPushList(sceneId, selfId, targetId)
	if (sceneId==17) then
		if IsMissionHaveDone(sceneId, selfId, x223008_g_MissionIdPre) > 0 then
        	    	return 1
        	end
        end
        return 0
	
end

--**********************************

--接受

--**********************************

function x223008_OnAccept(sceneId, selfId)

	        BeginEvent(sceneId)
		AddMission( sceneId, selfId, x223008_g_MissionId, x223008_g_ScriptId, 1, 0, 0)
		AddText(sceneId,"接受任务："..x223008_g_MissionName) 
		EndEvent()
		DispatchMissionTips(sceneId, selfId)
		                                               
	     
end



--**********************************

--放弃

--**********************************

function x223008_OnAbandon(sceneId, selfId)

	--删除玩家任务列表中对应的任务
	DelMission(sceneId, selfId, x223008_g_MissionId)
	for i, item in pairs(x223008_g_DemandItem) do
		DelItem(sceneId, selfId, item.id, item.num)
	end

end



--**********************************

--检测是否可以提交

--**********************************

function x223008_CheckSubmit( sceneId, selfId, targetId)
	misIndex = GetMissionIndexByID(sceneId,selfId,x223008_g_MissionId)
	if GetMissionParam(sceneId,selfId,misIndex,0) == x223008_g_DemandKill[1].num then
	        return 1
	end
	return 0

end



--**********************************

--提交

--**********************************

function x223008_OnSubmit(sceneId, selfId, targetId, selectRadioId)
	if DelMission(sceneId, selfId, x223008_g_MissionId) > 0 then
	
		MissionCom(sceneId, selfId, x223008_g_MissionId)
		AddExp(sceneId, selfId, x223008_g_ExpBonus)
		AddMoney(sceneId, selfId, x223008_g_MoneyBonus)
		for i, item in pairs(x223008_g_RadioItemBonus) do
	        if item.id == selectRadioId then
	        item={{selectRadioID, 1}}
	        end
	        end

		for i, item in pairs(x223008_g_DemandItem) do
		DelItem(sceneId, selfId, item.id, item.num)
		end
		--CallScriptFunction( x223008_g_ScriptIdNext.ScriptId, "OnDefaultEvent",sceneId, selfId, targetId )
	end
	

	
end



--**********************************

--杀死怪物或玩家

--**********************************

function x223008_OnKillObject(sceneId, selfId, objdataId)
	 if IsHaveMission(sceneId, selfId, x223008_g_MissionId) > 0 then 
	 misIndex = GetMissionIndexByID(sceneId,selfId,x223008_g_MissionId)  
	 num = GetMissionParam(sceneId,selfId,misIndex,0) 
	 	 if objdataId == x223008_g_DemandKill[1].id then 
       		    if num < x223008_g_DemandKill[1].num then
       		    	 SetMissionByIndex(sceneId,selfId,misIndex,0,num+1)
       		         BeginEvent(sceneId)
			 AddText(sceneId,format("杀死钦察军官   %d/%d", GetMissionParam(sceneId,selfId,misIndex,0),x223008_g_DemandKill[1].num )) 
			 EndEvent()
			 DispatchMissionTips(sceneId, selfId)
		    end
       		 end
       		 
      end  

end



--**********************************

--进入区域事件

--**********************************

function x223008_OnEnterArea(sceneId, selfId, zoneId)

end



--**********************************

--道具改变

--**********************************

function x223008_OnItemChanged(sceneId, selfId, itemdataId)

end

