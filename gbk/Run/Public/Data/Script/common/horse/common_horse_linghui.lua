--杀怪任务
--金国士兵
--MisDescBegin
--脚本号
x800020_g_ScriptId = 800020

--上一个任务的ID
--g_MissionIdPre =



--任务文本描述
x800020_g_MissionName="领回骑乘"

--MisDescEnd
--**********************************
--任务入口函数
--**********************************
function x800020_OnDefaultEvent( sceneId, selfId, targetId )	--点击该任务后执行此脚本
--		(这里写弹出打孔界面的脚本接口)
end

--**********************************
--列举事件
--**********************************
function x800020_OnEnumerate( sceneId, selfId, targetId )
	AddNumText(sceneId,x800020_g_ScriptId,x800020_g_MissionName);
end


--********************
--检测接受条件
--**********************************
function x800020_CheckAccept( sceneId, selfId )
		return 1
end

--**********************************
--接受
--**********************************
function x800020_OnAccept( sceneId, selfId )

end

--**********************************
--放弃
--**********************************
function x800020_OnAbandon( sceneId, selfId )

end

--**********************************
--继续
--**********************************
function x800020_OnContinue( sceneId, selfId, targetId )

end

--**********************************
--检测是否可以提交
--**********************************
function x800020_CheckSubmit( sceneId, selfId )

end

--**********************************
--提交
--**********************************
function x800020_OnSubmit( sceneId, selfId, targetId,selectRadioId )

end

--**********************************
--杀死怪物或玩家
--**********************************
function x800020_OnKillObject( sceneId, selfId, objdataId )

end

--**********************************
--进入区域事件
--**********************************
function x800020_OnEnterArea( sceneId, selfId, zoneId )
end

--**********************************
--道具改变
--**********************************
function x800020_OnItemChanged( sceneId, selfId, itemdataId )
end
