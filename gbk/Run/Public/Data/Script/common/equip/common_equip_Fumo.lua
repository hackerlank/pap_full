--功能：炼化装备

x500010_g_ScriptId = 500010
x500010_g_MissionName="装备附魔"
--**********************************

--任务入口函数

--**********************************

function x500010_OnDefaultEvent(sceneId, selfId, targetId)	--点击该任务后执行此脚本
--	DismantleSouXiaItem( sceneId, selfId, targetId)
end



--**********************************

--列举事件

--**********************************

function x500010_OnEnumerate(sceneId, selfId, targetId)
		AddNumText(sceneId, x500010_g_ScriptId, x500010_g_MissionName)
end



--**********************************

--检测接受条件

--**********************************

function x500010_CheckAccept(sceneId, selfId, targetId)

end

--**********************************

--接受

--**********************************

function x500010_OnAccept(sceneId, selfId)
                                                                   
	     
end



--**********************************

--放弃

--**********************************

function x500010_OnAbandon(sceneId, selfId)

end



--**********************************

--检测是否可以提交

--**********************************

function x500010_CheckSubmit( sceneId, selfId, targetId)

end



--**********************************

--提交

--**********************************

function x500010_OnSubmit(sceneId, selfId, targetId, selectRadioId)
	
end



--**********************************

--杀死怪物或玩家

--**********************************

function x500010_OnKillObject(sceneId, selfId, objdataId)

end



--**********************************

--进入区域事件

--**********************************

function x500010_OnEnterArea(sceneId, selfId, zoneId)

end



--**********************************

--道具改变

--**********************************

function x500010_OnItemChanged(sceneId, selfId, itemdataId)

end

