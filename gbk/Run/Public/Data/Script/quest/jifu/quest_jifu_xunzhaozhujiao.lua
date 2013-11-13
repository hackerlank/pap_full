--寻找主教

--MisDescBegin
x225001_g_ScriptId = 225001
x225001_g_MissionIdPre =322
x225001_g_MissionId = 323
x225001_g_MissionKind = 22
x225001_g_MissionLevel = 110
x225001_g_ScriptIdNext = {ScriptId = 225002 ,LV = 1 }
x225001_g_Name	="速不台" 
x225001_g_DemandItem ={}
x225001_g_DemandKill ={}	

x225001_g_MissionName="寻找主教"
x225001_g_MissionInfo="    突然想起来一个问题，基辅的主教跑到哪里去了呢？没有听说他逃出基辅城啊。\n \n    有消息说东面的#G贵族花园#W里面有一群衣着华丽的人，估计就是主教逃到那里去了。身为主教还没有普通人虔诚，居然不留在教堂里。\n \n    帮我去贵族花园里面去看看情况吧。"
x225001_g_MissionTarget="    帮#G速不台#W去查看#G贵族花园#W的情况。"		                                                                                               
x225001_g_MissionComplete="    主教带着人在挖坑？旁边还有一个箱子？"					--完成任务npc说话的话
x225001_g_ContinueInfo="    那个花园我看不出有哪一点好的，不知道为什么基辅的贵族这么喜欢。"
--任务奖励
x225001_g_MoneyBonus = 10000

--固定物品奖励，最多8种
x225001_g_ItemBonus={}

--可选物品奖励，最多8种
x225001_g_RadioItemBonus={}

--MisDescEnd
x225001_g_ExpBonus = 4000
--**********************************

--任务入口函数

--**********************************

function x225001_OnDefaultEvent(sceneId, selfId, targetId)	--点击该任务后执行此脚本

	--检测列出条件
	if x225001_CheckPushList(sceneId, selfId, targetId) <= 0 then
		return
	end

	--如果已接此任务
	if IsHaveMission(sceneId,selfId, x225001_g_MissionId) > 0 then
	misIndex = GetMissionIndexByID(sceneId,selfId,x225001_g_MissionId)
		if x225001_CheckSubmit(sceneId, selfId, targetId) <= 0 then
                        BeginEvent(sceneId)
			AddText(sceneId,"#Y"..x225001_g_MissionName)
			AddText(sceneId,x225001_g_ContinueInfo)
		        AddText(sceneId,"#Y任务目标#W") 
			AddText(sceneId,x225001_g_MissionTarget) 
			AddText(sceneId,format("\n    到贵族花园寻找主教踪迹   %d/1", GetMissionParam(sceneId,selfId,misIndex,0) ))
			EndEvent()
			DispatchEventList(sceneId, selfId, targetId)
		end

		     
                if x225001_CheckSubmit(sceneId, selfId, targetId) > 0 then
                     BeginEvent(sceneId)
                     AddText(sceneId,"#Y"..x225001_g_MissionName)
		     AddText(sceneId,x225001_g_MissionComplete)
		     EndEvent()
                     DispatchMissionContinueInfo(sceneId, selfId, targetId, x225001_g_ScriptId, x225001_g_MissionId)
                end

        elseif x225001_CheckAccept(sceneId, selfId, targetId) > 0 then
	    	
		--发送任务接受时显示的信息
		BeginEvent(sceneId)
		AddText(sceneId,"#Y"..x225001_g_MissionName)
                AddText(sceneId,x225001_g_MissionInfo) 
		AddText(sceneId,"#Y任务目标#W") 
		AddText(sceneId,x225001_g_MissionTarget) 
		AddMoneyBonus(sceneId, x225001_g_MoneyBonus)	
		EndEvent()
		
		DispatchMissionInfo(sceneId, selfId, targetId, x225001_g_ScriptId, x225001_g_MissionId)
        end
	
end



--**********************************

--列举事件

--**********************************

function x225001_OnEnumerate(sceneId, selfId, targetId)


	--如果玩家完成过这个任务
	if IsMissionHaveDone(sceneId, selfId, x225001_g_MissionId) > 0 then
		return 
	end
	--如果已接此任务
	if  x225001_CheckPushList(sceneId, selfId, targetId) > 0 then
		AddNumText(sceneId, x225001_g_ScriptId, x225001_g_MissionName)
	end
	
end



--**********************************

--检测接受条件

--**********************************

function x225001_CheckAccept(sceneId, selfId, targetId)

	if IsHaveMission(sceneId,selfId, x225001_g_MissionId)<= 0 then 
					return 1
	end
	return 0
end


--**********************************

--检测查看条件

--**********************************

function x225001_CheckPushList(sceneId, selfId, targetId)
	if (sceneId==16) then
		if IsMissionHaveDone(sceneId, selfId, x225001_g_MissionIdPre) > 0 then
                    return 1
        	end
        end
	return 0
	
end

--**********************************

--接受

--**********************************

function x225001_OnAccept(sceneId, selfId)

	        BeginEvent(sceneId)
		AddMission( sceneId, selfId, x225001_g_MissionId, x225001_g_ScriptId, 1, 0, 0)
		AddText(sceneId,"接受任务："..x225001_g_MissionName) 
		EndEvent()
		DispatchMissionTips(sceneId, selfId)
		misIndex = GetMissionIndexByID(sceneId,selfId,x225001_g_MissionId)
		                                              
	     
end



--**********************************

--放弃

--**********************************

function x225001_OnAbandon(sceneId, selfId)

	--删除玩家任务列表中对应的任务
	DelMission(sceneId, selfId, x225001_g_MissionId)

end



--**********************************

--检测是否可以提交

--**********************************

function x225001_CheckSubmit( sceneId, selfId, targetId)
	misIndex = GetMissionIndexByID(sceneId,selfId,x225001_g_MissionId)
	if GetMissionParam(sceneId,selfId,misIndex,0) == 1 then
	        return 1
	end
	return 0

end



--**********************************

--提交

--**********************************

function x225001_OnSubmit(sceneId, selfId, targetId, selectRadioId)

	if DelMission(sceneId, selfId, x225001_g_MissionId) > 0 then
	
		MissionCom(sceneId, selfId, x225001_g_MissionId)
		AddExp(sceneId, selfId, x225001_g_ExpBonus)
		AddMoney(sceneId, selfId, x225001_g_MoneyBonus)
		for i, item in pairs(x225001_g_RadioItemBonus) do
	        if item.id == selectRadioId then
	        item={{selectRadioID, 1}}
	        end
	        end

		for i, item in pairs(x225001_g_DemandItem) do
		DelItem(sceneId, selfId, item.id, item.num)
		end
		CallScriptFunction( x225001_g_ScriptIdNext.ScriptId, "OnDefaultEvent",sceneId, selfId, targetId )
	end
	

	
end



--**********************************

--杀死怪物或玩家

--**********************************

function x225001_OnKillObject(sceneId, selfId, objdataId)
	
end



--**********************************

--进入区域事件

--**********************************

function x225001_OnEnterArea(sceneId, selfId, zoneId)
	misIndex = GetMissionIndexByID(sceneId,selfId,x225001_g_MissionId)
	if GetMissionParam(sceneId,selfId,misIndex,0) == 0 then
		if IsHaveMission(sceneId,selfId, x225001_g_MissionId)> 0 then
		SetMissionByIndex(sceneId,selfId,misIndex,0,1)
		BeginEvent(sceneId)
		AddText(sceneId,"    到贵族花园寻找主教踪迹   1/1") 
		EndEvent()
		DispatchMissionTips(sceneId, selfId)
		BeginEvent(sceneId)
		AddText(sceneId,"    远远的看去，基辅的主教在指挥两个牧师挖坑。在主教的身边放着一个金属箱子，看样子主教是要把箱子埋进深坑。") 
		EndEvent()
		DispatchEventList(sceneId, selfId, targetId)
		end
	end


end

function x225001_OnTimer(sceneId, selfId )

end
function x225001_OnLeaveArea(sceneId, selfId )

end


--**********************************

--道具改变

--**********************************

function x225001_OnItemChanged(sceneId, selfId, itemdataId)

end

