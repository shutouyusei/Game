// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class MaK : ModuleRules
{
	public MaK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","UMG","AIModule" });

    PrivateDependencyModuleNames.AddRange(new string[] {  });
    
    PublicIncludePaths.Add(ModuleDirectory + "/../Lua/include");
    //Module include PublicIncludePaths
    PublicIncludePaths.Add(ModuleDirectory + "/DataBase/Item/include");
    PublicIncludePaths.Add(ModuleDirectory + "/UserBelongings/include");
    PublicIncludePaths.Add(ModuleDirectory + "/UseHandler");
    PublicIncludePaths.Add(ModuleDirectory + "/LuaHandler");
    PublicIncludePaths.Add(ModuleDirectory + "/Status/include");
    PublicIncludePaths.Add(ModuleDirectory + "/Character");
    PublicIncludePaths.Add(ModuleDirectory + "/Ability");
    //
    PublicAdditionalLibraries.Add(ModuleDirectory + "/../Lua/lib/lua54.lib");
    var luaDLLPath = ModuleDirectory + "/../../Binaries/Win64/lua54.dll";
    PublicDelayLoadDLLs.Add("lua54.dll");
    RuntimeDependencies.Add(luaDLLPath);
  }
}
