--功能：中心传送
--NPC：中心传送使者

x300419_g_ScriptId = 300419
x300419_g_MissionName="正阳门"
x300419_g_TransScriptId = 800019
x300419_g_TransPos="zhengyangmen"

--**********************************

--任务入口函数

--**********************************

function x300419_OnDefaultEvent(sceneId, selfId, targetId)	--点击该任务后执行此脚本
	CallScriptFunction(x300419_g_TransScriptId, "TransferToWorld",sceneId,selfId,x300419_g_TransPos)
end



--**********************************

--列举事件

--**********************************

function x300419_OnEnumerate(sceneId, selfId, targetId)
		AddNumText(sceneId, x300419_g_ScriptId, x300419_g_MissionName)
end



--**********************************

--检测接受条件

--**********************************

function x300419_CheckAccept(sceneId, selfId, targetId)

end

--**********************************

--接受

--**********************************

function x300419_OnAccept(sceneId, selfId)
                                                                   
	     
end



--**********************************

--放弃

--**********************************

function x300419_OnAbandon(sceneId, selfId)

end



--**********************************

--检测是否可以提交

--**********************************

function x300419_CheckSubmit( sceneId, selfId, targetId)

end



--**********************************

--提交

--**********************************

function x300419_OnSubmit(sceneId, selfId, targetId, selectRadioId)
	
end



--**********************************

--杀死怪物或玩家

--**********************************

function x300419_OnKillObject(sceneId, selfId, objdataId)

end



--**********************************

--进入区域事件

--**********************************

function x300419_OnEnterArea(sceneId, selfId, zoneId)

end



--**********************************

--道具改变

--**********************************

function x300419_OnItemChanged(sceneId, selfId, itemdataId)

end