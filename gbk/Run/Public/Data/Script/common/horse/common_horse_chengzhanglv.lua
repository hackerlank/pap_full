--杀怪任务
--金国士兵
--MisDescBegin
--脚本号
x800018_g_ScriptId = 800018

--上一个任务的ID
--g_MissionIdPre =



--任务文本描述
x800018_g_MissionName="成长率鉴定"

--MisDescEnd
--**********************************
--任务入口函数
--**********************************
function x800018_OnDefaultEvent( sceneId, selfId, targetId )	--点击该任务后执行此脚本
--		(这里写弹出成长率鉴定界面的脚本接口)
end

--**********************************
--列举事件
--**********************************
function x800018_OnEnumerate( sceneId, selfId, targetId )
	AddNumText(sceneId,x800018_g_ScriptId,x800018_g_MissionName);
end


--********************
--检测接受条件
--**********************************
function x800018_CheckAccept( sceneId, selfId )
		return 1
end

--**********************************
--接受
--**********************************
function x800018_OnAccept( sceneId, selfId )

end

--**********************************
--放弃
--**********************************
function x800018_OnAbandon( sceneId, selfId )

end

--**********************************
--继续
--**********************************
function x800018_OnContinue( sceneId, selfId, targetId )

end

--**********************************
--检测是否可以提交
--**********************************
function x800018_CheckSubmit( sceneId, selfId )

end

--**********************************
--提交
--**********************************
function x800018_OnSubmit( sceneId, selfId, targetId,selectRadioId )

end

--**********************************
--杀死怪物或玩家
--**********************************
function x800018_OnKillObject( sceneId, selfId, objdataId )

end

--**********************************
--进入区域事件
--**********************************
function x800018_OnEnterArea( sceneId, selfId, zoneId )
end

--**********************************
--道具改变
--**********************************
function x800018_OnItemChanged( sceneId, selfId, itemdataId )
end
