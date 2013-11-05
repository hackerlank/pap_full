--�󺹵�ϴ��һ

--MisDescBegin
x212009_g_ScriptId = 212009
--x212009_g_MissionIdPre =41
x212009_g_MissionId = 256
x212009_g_MissionKind = 17
x212009_g_MissionLevel = 70
x212009_g_ScriptIdNext = {ScriptId = 212010 ,LV = 1 }
x212009_g_Name	="�𴦻�" 
x212009_g_DemandItem ={}
x212009_g_DemandKill ={{id=429,num=1}}

x212009_g_MissionName="�󺹵�ϴ��һ"
x212009_g_MissionInfo="    "  --��������
x212009_g_MissionInfo2="���󺹱���޵Ķ�ħ�������޷��԰Σ�����Ҫ�����һ�ѣ�ɱ����#G�������#Wָ��ս������������#R�Ե���#W��Ϩ��󺹳�޵�ŭ��"
x212009_g_MissionTarget="    #G�𴦻�#WΪ��Ҫ��󺹵�ŭ��Ҫ��ɱ����#G�������#Wָ��ս������������#R�Ե���#W��"		                                                                                               
x212009_g_MissionComplete="    ��л����ҪΪ��ϴ���ˡ�"					--�������npc˵���Ļ�
x212009_g_ContinueInfo="    ɱһ�˶��Ȱ��ˣ���������ƣ���ɱ���Ե�������"
--������
x212009_g_MoneyBonus = 500

--�̶���Ʒ���������8��
x212009_g_ItemBonus={}

--��ѡ��Ʒ���������8��
x212009_g_RadioItemBonus={}

--MisDescEnd
x212009_g_ExpBonus = 4000
--**********************************

--������ں���

--**********************************

function x212009_OnDefaultEvent(sceneId, selfId, targetId)	--����������ִ�д˽ű�

	--����г�����
	if x212009_CheckPushList(sceneId, selfId, targetId) <= 0 then
		return
	end

	--����ѽӴ�����
	if IsHaveMission(sceneId,selfId, x212009_g_MissionId) > 0 then
	misIndex = GetMissionIndexByID(sceneId,selfId,x212009_g_MissionId)
		if x212009_CheckSubmit(sceneId, selfId, targetId) <= 0 then
                        BeginEvent(sceneId)
			AddText(sceneId,"#Y"..x212009_g_MissionName)
			AddText(sceneId,x212009_g_ContinueInfo)
		        AddText(sceneId,"#Y����Ŀ��#W") 
			AddText(sceneId,x212009_g_MissionTarget) 
			AddText(sceneId,format("\n    ɱ���Ե���   %d/%d", GetMissionParam(sceneId,selfId,misIndex,0),x212009_g_DemandKill[1].num ))
			EndEvent()
			DispatchEventList(sceneId, selfId, targetId)
		end

		     
                if x212009_CheckSubmit(sceneId, selfId, targetId) > 0 then
                     BeginEvent(sceneId)
                     AddText(sceneId,"#Y"..x212009_g_MissionName)
		     AddText(sceneId,x212009_g_MissionComplete)
		     AddMoneyBonus(sceneId, x212009_g_MoneyBonus)
		     EndEvent()
                     DispatchMissionContinueInfo(sceneId, selfId, targetId, x212009_g_ScriptId, x212009_g_MissionId)
                end

        elseif x212009_CheckAccept(sceneId, selfId, targetId) > 0 then
	    	
		--�����������ʱ��ʾ����Ϣ
		BeginEvent(sceneId)
		AddText(sceneId,"#Y"..x212009_g_MissionName)
                AddText(sceneId,x212009_g_MissionInfo..GetName(sceneId, selfId)..x212009_g_MissionInfo2) 
		AddText(sceneId,"#Y����Ŀ��#W") 
		AddText(sceneId,x212009_g_MissionTarget) 
		AddMoneyBonus(sceneId, x212009_g_MoneyBonus)
		EndEvent()
		
		DispatchMissionInfo(sceneId, selfId, targetId, x212009_g_ScriptId, x212009_g_MissionId)
        end
	
end



--**********************************

--�о��¼�

--**********************************

function x212009_OnEnumerate(sceneId, selfId, targetId)


	--��������ɹ��������
	if IsMissionHaveDone(sceneId, selfId, x212009_g_MissionId) > 0 then
		return 
	end
	--����ѽӴ�����
	if  x212009_CheckPushList(sceneId, selfId, targetId) > 0 then
		AddNumText(sceneId, x212009_g_ScriptId, x212009_g_MissionName)
	end
	
end



--**********************************

--����������

--**********************************

function x212009_CheckAccept(sceneId, selfId, targetId)

	if (GetName(sceneId,targetId)==x212009_g_Name) then 
					return 1
	end
	return 0
end


--**********************************

--���鿴����

--**********************************

function x212009_CheckPushList(sceneId, selfId, targetId)
	if (sceneId==12) then
        	    	return 1
        end
        return 0
	
end

--**********************************

--����

--**********************************

function x212009_OnAccept(sceneId, selfId)

	        BeginEvent(sceneId)
		AddMission( sceneId, selfId, x212009_g_MissionId, x212009_g_ScriptId, 1, 0, 0)
		AddText(sceneId,"��������"..x212009_g_MissionName) 
		EndEvent()
		DispatchMissionTips(sceneId, selfId)
		                                               
	     
end



--**********************************

--����

--**********************************

function x212009_OnAbandon(sceneId, selfId)

	--ɾ����������б��ж�Ӧ������
	DelMission(sceneId, selfId, x212009_g_MissionId)
	for i, item in x212009_g_DemandItem do
		DelItem(sceneId, selfId, item.id, item.num)
	end

end



--**********************************

--����Ƿ�����ύ

--**********************************

function x212009_CheckSubmit( sceneId, selfId, targetId)
	misIndex = GetMissionIndexByID(sceneId,selfId,x212009_g_MissionId)
	if GetMissionParam(sceneId,selfId,misIndex,0) == x212009_g_DemandKill[1].num then
	        return 1
	end
	return 0

end



--**********************************

--�ύ

--**********************************

function x212009_OnSubmit(sceneId, selfId, targetId, selectRadioId)
	if DelMission(sceneId, selfId, x212009_g_MissionId) > 0 then
	
		MissionCom(sceneId, selfId, x212009_g_MissionId)
		AddExp(sceneId, selfId, x212009_g_ExpBonus)
		AddMoney(sceneId, selfId, x212009_g_MoneyBonus)
		for i, item in x212009_g_RadioItemBonus do
	        if item.id == selectRadioId then
	        item={{selectRadioID, 1}}
	        end
	        end

		for i, item in x212009_g_DemandItem do
		DelItem(sceneId, selfId, item.id, item.num)
		end
		CallScriptFunction( x212009_g_ScriptIdNext.ScriptId, "OnDefaultEvent",sceneId, selfId, targetId )
	end
	

	
end



--**********************************

--ɱ����������

--**********************************

function x212009_OnKillObject(sceneId, selfId, objdataId)
	 if IsHaveMission(sceneId, selfId, x212009_g_MissionId) > 0 then 
	 misIndex = GetMissionIndexByID(sceneId,selfId,x212009_g_MissionId)  
	 num = GetMissionParam(sceneId,selfId,misIndex,0) 
	 	 if objdataId == x212009_g_DemandKill[1].id then 
       		    if num < x212009_g_DemandKill[1].num then
       		    	 SetMissionByIndex(sceneId,selfId,misIndex,0,num+1)
       		         BeginEvent(sceneId)
			 AddText(sceneId,format("ɱ���Ե���   %d/%d", GetMissionParam(sceneId,selfId,misIndex,0),x212009_g_DemandKill[1].num )) 
			 EndEvent()
			 DispatchMissionTips(sceneId, selfId)
		    end
       		 end
       		 
      end  

end



--**********************************

--���������¼�

--**********************************

function x212009_OnEnterArea(sceneId, selfId, zoneId)

end



--**********************************

--���߸ı�

--**********************************

function x212009_OnItemChanged(sceneId, selfId, itemdataId)

end
