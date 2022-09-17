#pragma once

#include <functional>

namespace alt
{
	class CEvent
	{
	public:
		enum class Type : uint16_t
		{
			NONE,

			// Server
			SERVER_STARTED,

			// Shared
			PLAYER_CONNECT,
			PLAYER_BEFORE_CONNECT,
			PLAYER_DISCONNECT,
			PLAYER_DENIED,

			CONNECTION_QUEUE_ADD,
			CONNECTION_QUEUE_REMOVE,

			RESOURCE_START,
			RESOURCE_STOP,
			RESOURCE_ERROR,
			
			SERVER_SCRIPT_EVENT,
			CLIENT_SCRIPT_EVENT,

			META_CHANGE,
			SYNCED_META_CHANGE,
			STREAM_SYNCED_META_CHANGE,
			GLOBAL_META_CHANGE,
			GLOBAL_SYNCED_META_CHANGE,
			LOCAL_SYNCED_META_CHANGE,

			PLAYER_DAMAGE,
			PLAYER_DEATH,
			FIRE_EVENT,
			EXPLOSION_EVENT,
			START_PROJECTILE_EVENT,
			WEAPON_DAMAGE_EVENT,
			VEHICLE_DESTROY,
			VEHICLE_DAMAGE,

			CHECKPOINT_EVENT,
			COLSHAPE_EVENT,
			PLAYER_ENTER_VEHICLE,
			PLAYER_ENTERING_VEHICLE,
			PLAYER_LEAVE_VEHICLE,
			PLAYER_CHANGE_VEHICLE_SEAT,
			PLAYER_WEAPON_CHANGE,
			PLAYER_REQUEST_CONTROL,

			VEHICLE_ATTACH,
			VEHICLE_DETACH,
			NETOWNER_CHANGE,

			REMOVE_ENTITY_EVENT,
			CREATE_BASE_OBJECT_EVENT,
			REMOVE_BASE_OBJECT_EVENT,

			DATA_NODE_RECEIVED_EVENT,

			CONSOLE_COMMAND_EVENT,

			PLAYER_CHANGE_ANIMATION_EVENT,

			PLAYER_CHANGE_INTERIOR_EVENT,

			PLAYER_WEAPON_SHOOT_EVENT,

			// Client
			CONNECTION_COMPLETE,
			DISCONNECT_EVENT,
			WEB_VIEW_EVENT,
			KEYBOARD_EVENT,
			GAME_ENTITY_CREATE,
			GAME_ENTITY_DESTROY,
			WEB_SOCKET_CLIENT_EVENT,
			AUDIO_EVENT,
			TASK_CHANGE,
			SPAWNED,
			RMLUI_EVENT,
			WINDOW_FOCUS_CHANGE,
			WINDOW_RESOLUTION_CHANGE,

			ALL,
			SIZE
		};

		CEvent(Type _type) :type(_type) { }
		virtual ~CEvent() = default;

		Type GetType() const { return type; };
		bool WasCancelled() const { return cancelled; }
		void Cancel() const { cancelled = true; }

	private:
		Type type;
		mutable bool cancelled = false;
	};
}
