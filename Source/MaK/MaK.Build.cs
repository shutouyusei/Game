// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class MaK : ModuleRules
{
	public MaK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","UMG" });

    PrivateDependencyModuleNames.AddRange(new string[] {  });
    
    PublicIncludePaths.Add(ModuleDirectory + "/../Lua/include");
    //Module include PublicIncludePaths
    PublicIncludePaths.Add(ModuleDirectory + "/DataBase/Item/include");
    PublicIncludePaths.Add(ModuleDirectory + "/UserBelongings/ItemBelongings/include");
    //
    PublicAdditionalLibraries.Add(ModuleDirectory + "/../Lua/lib/lua54.lib");
    var luaDLLPath = ModuleDirectory + "/../../Binaries/Win64/lua54.dll";
    PublicDelayLoadDLLs.Add("lua54.dll");
    RuntimeDependencies.Add(luaDLLPath);
  }
}
