--功能：使用烹饪技能

x520004_g_ScriptId = 520004
x520004_g_MissionName="使用烹饪技能"
--**********************************

--任务入口函数

--**********************************

function x520004_OnDefaultEvent(sceneId, selfId, targetId)	--点击该任务后执行此脚本
--	DismantleSouXiaItem( sceneId, selfId, targetId)
end



--**********************************

--列举事件

--**********************************

function x520004_OnEnumerate(sceneId, selfId, targetId)
		AddNumText(sceneId, x520004_g_ScriptId, x520004_g_MissionName)
end



--**********************************

--检测接受条件

--**********************************

function x520004_CheckAccept(sceneId, selfId, targetId)

end

--**********************************

--接受

--**********************************

function x520004_OnAccept(sceneId, selfId)
                                                                   
	     
end



--**********************************

--放弃

--**********************************

function x520004_OnAbandon(sceneId, selfId)

end



--**********************************

--检测是否可以提交

--**********************************

function x520004_CheckSubmit( sceneId, selfId, targetId)

end



--**********************************

--提交

--**********************************

function x520004_OnSubmit(sceneId, selfId, targetId, selectRadioId)
	
end



--**********************************

--杀死怪物或玩家

--**********************************

function x520004_OnKillObject(sceneId, selfId, objdataId)

end



--**********************************

--进入区域事件

--**********************************

function x520004_OnEnterArea(sceneId, selfId, zoneId)

end



--**********************************

--道具改变

--**********************************

function x520004_OnItemChanged(sceneId, selfId, itemdataId)

end
