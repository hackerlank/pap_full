--功能：帮会相关
--NPC：祖兰德

--MisDescBegin
x211000_g_ScriptId = 211000

--MisDescEnd
--**********************************

--任务入口函数

--**********************************

function x211000_OnDefaultEvent(sceneId, selfId, targetId)	--点击该任务后执行此脚本
	GuildCreate(sceneId, selfId, targetId);
end



--**********************************

--列举事件

--**********************************

function x211000_OnEnumerate(sceneId, selfId, targetId)
		AddNumText(sceneId, x211000_g_ScriptId, "创建帮会")
end



--**********************************

--检测接受条件

--**********************************

function x211000_CheckAccept(sceneId, selfId, targetId)

end
--**********************************

--接受

--**********************************

function x211000_OnAccept(sceneId, selfId)

end



--**********************************

--放弃

--**********************************

function x211000_OnAbandon(sceneId, selfId)

end



--**********************************

--检测是否可以提交

--**********************************

function x211000_CheckSubmit( sceneId, selfId, targetId)

end



--**********************************

--提交

--**********************************

function x211000_OnSubmit(sceneId, selfId, targetId, selectRadioId)

end



--**********************************

--杀死怪物或玩家

--**********************************

function x211000_OnKillObject(sceneId, selfId, objdataId)

end



--**********************************

--进入区域事件

--**********************************

function x211000_OnEnterArea(sceneId, selfId, zoneId)

end



--**********************************

--道具改变

--**********************************

function x211000_OnItemChanged(sceneId, selfId, itemdataId)

end