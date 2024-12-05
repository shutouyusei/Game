// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class MaK : ModuleRules
{
	public MaK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","UMG","Slate","SlateCore" });

    PrivateDependencyModuleNames.AddRange(new string[] {  });
    
    PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Lua","include"));
    if(Target.Platform == UnrealTargetPlatform.Win64)
    {
      PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory,"Lua", "lib", "lua54.lib"));
    }
    var luaDLLPath = ModuleDirectory + "../../Binaries/Win64/lua54.dll";
    PublicDelayLoadDLLs.Add("lua54.dll");
    RuntimeDependencies.Add(luaDLLPath);
  }
}
