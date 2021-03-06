/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "bladerunner/script/script.h"

namespace BladeRunner {

void ScriptPS03::InitializeScene() {
	if (Game_Flag_Query(39)) {
		Actor_Set_At_XYZ(0, -674.0f, -354.0f, 550.0f, 900);
		Setup_Scene_Information(-674.0f, -354.62f, 550.0f, 900);
		Game_Flag_Reset(39);
	} else if (Game_Flag_Query(135)) {
		Setup_Scene_Information(-875.0f, -354.62f, -1241.0f, 450);
		Game_Flag_Reset(135);
	} else {
		Setup_Scene_Information(-569.54f, -354.62f, -1076.15f, 475);
		Game_Flag_Reset(132);
	}
	Scene_Exit_Add_2D_Exit(0, 0, 460, 639, 479, 2);
	Scene_Exit_Add_2D_Exit(1, 449, 273, 508, 329, 0);
	if (Global_Variable_Query(1) > 1) {
		Scene_Exit_Add_2D_Exit(2, 358, 245, 411, 288, 0);
	}
	Ambient_Sounds_Remove_All_Non_Looping_Sounds(0);
	Ambient_Sounds_Add_Looping_Sound(45, 35, 0, 1);
	Ambient_Sounds_Add_Sound(90, 5, 50, 7, 7, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(91, 5, 50, 7, 7, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(92, 5, 60, 33, 33, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(93, 5, 60, 33, 33, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(94, 5, 60, 33, 33, -100, 100, -101, -101, 0, 0);
	Scene_Loop_Set_Default(1);
}

void ScriptPS03::SceneLoaded() {
	Obstacle_Object("TABLE05", true);
	Unclickable_Object("COP1PS03");
	Unclickable_Object("COP2PS03");
}

bool ScriptPS03::MouseClick(int x, int y) {
	return false;
}

bool ScriptPS03::ClickedOn3DObject(const char *objectName, bool a2) {
	return false;
}

bool ScriptPS03::ClickedOnActor(int actorId) {
	return false;
}

bool ScriptPS03::ClickedOnItem(int itemId, bool a2) {
	return false;
}

bool ScriptPS03::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_XYZ(0, -674.0f, -354.0f, 550.0f, 0, 1, false, 0)) {
			Game_Flag_Set(42);
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Set_Enter(64, 68);
		}
		return true;
	}
	if (exitId == 1) {
		if (!Loop_Actor_Walk_To_XYZ(0, -569.54f, -354.62f, -1076.15f, 0, 1, false, 0)) {
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Set_Enter(62, 66);
			Game_Flag_Reset(478);
			if (Global_Variable_Query(1) < 4) {
				Actor_Set_Goal_Number(4, 100);
			}
		}
		return true;
	}
	if (exitId == 2) {
		if (!Loop_Actor_Walk_To_XYZ(0, -875.0f, -354.0f, -1241.0f, 0, 1, false, 0)) {
			Game_Flag_Set(134);
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Set_Enter(68, 77);
		}
		return true;
	}
	return false;
}

bool ScriptPS03::ClickedOn2DRegion(int region) {
	return false;
}

void ScriptPS03::SceneFrameAdvanced(int frame) {
}

void ScriptPS03::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void ScriptPS03::PlayerWalkedIn() {
	if (!Game_Flag_Query(478)) {
		Game_Flag_Set(478);
		//return true;
	}
	//return false;
}

void ScriptPS03::PlayerWalkedOut() {
}

void ScriptPS03::DialogueQueueFlushed(int a1) {
}

} // End of namespace BladeRunner
