// Some copyright should be here...

using UnrealBuildTool;
using System.IO;

public class DTDMessaging : ModuleRules
{
    public DTDMessaging(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.Add("Core");

        PrivateDependencyModuleNames.Add("CoreUObject");
        PrivateDependencyModuleNames.Add("Engine");
        PrivateDependencyModuleNames.Add("Slate");
        PrivateDependencyModuleNames.Add("SlateCore");
        PrivateDependencyModuleNames.Add("DTDAnalytics");

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.Add("Launch");
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "DTDMessaging_UPL_Android.xml"));

            if (Target.Version.MajorVersion < 5 || Target.Version.MajorVersion >= 5 && Target.Version.MinorVersion < 3)
            {
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "DTDMessaging_UPL_Android_Pack_1.xml"));
            }
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            if (Target.Configuration == UnrealTargetConfiguration.Shipping)
            {
                PublicAdditionalFrameworks.Add(new Framework("DTDMessagingUnreal", "../../ThirdParty/iOS/Shipping/DTDMessagingUnreal.framework.zip", null, true));
            }
            else
            {
                PublicAdditionalFrameworks.Add(new Framework("DTDMessagingUnreal", "../../ThirdParty/iOS/Debug/DTDMessagingUnreal.framework.zip", null, true));
            }

            PublicFrameworks.AddRange(new string[]
            {
                "UserNotifications"
            });
        }
    }
}
