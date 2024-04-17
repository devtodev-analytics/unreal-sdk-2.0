// Copyright (c) devtodev. All rights reserved.

using System;
using System.IO;
using System.Diagnostics;
using UnrealBuildTool;

public class DTDAnalytics : ModuleRules
{
    public DTDAnalytics(ReadOnlyTargetRules Target) : base(Target)
    {
        bool IS_COPPA_ENABLED = false;

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.Add("Core");
        PublicDependencyModuleNames.Add("Json");
        PublicDependencyModuleNames.Add("JsonUtilities"); 
        PrivateDependencyModuleNames.Add("CoreUObject");
        PrivateDependencyModuleNames.Add("Engine");
        PrivateDependencyModuleNames.Add("Slate");
        PrivateDependencyModuleNames.Add("SlateCore");

        var testingFolder = Path.Combine(ModuleDirectory, "Public", "Testing");
        if (Directory.Exists(testingFolder))
        {
            PrivateIncludePaths.Add(testingFolder);
        }

        if (Target.bBuildEditor)
        {
           PrivateDependencyModuleNames.Add("UnrealEd");
        }

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.Add("Launch");
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "DTDAnalytics_UPL_Android.xml"));

            if (!IS_COPPA_ENABLED) {
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "DTDAnalytics_UPL_Google_Dependenses.xml"));
            }
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            if (Target.Configuration == UnrealTargetConfiguration.Shipping)
            {
                PublicAdditionalFrameworks.Add(new Framework("DTDAnalyticsUnreal", "../../ThirdParty/iOS/Shipping/DTDAnalyticsUnreal.framework.zip", null, true));
            }
            else
            {
                PublicAdditionalFrameworks.Add(new Framework("DTDAnalyticsUnreal", "../../ThirdParty/iOS/Debug/DTDAnalyticsUnreal.framework.zip", null, true));
            }

            PublicFrameworks.AddRange(new string[]
            {
                "StoreKit",
                "UserNotifications"
            });

            if (!IS_COPPA_ENABLED) {
                PublicFrameworks.AddRange(new string[]
                {
                    "AdSupport"
                });

                PublicWeakFrameworks.AddRange(new string[] 
                {
                    "AppTrackingTransparency"
                });
            }
        }
        else if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // var architecture = Target.Platform == UnrealTargetPlatform.Win64 ? "Win64" : "Win32";
            var architecture = "Win64";
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "DevToDev.Analytics.Unreal.Windows.lib"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/DevToDev.Analytics.Unreal.Windows.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "DevToDev.Analytics.Unreal.Windows.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/DevToDev.Analytics.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "DevToDev.Analytics.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/DevToDev.Core.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "DevToDev.Core.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/Newtonsoft.Json.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "Newtonsoft.Json.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/System.Data.SQLite.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Data.SQLite.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/SQLite.Interop.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "SQLite.Interop.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/libzstd.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "libzstd.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/ZstdNet.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "ZstdNet.dll"));
            //ZstdNet dependencies
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/System.Buffers.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Buffers.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/System.Memory.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Memory.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/System.Numerics.Vectors.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Numerics.Vectors.dll"));
            RuntimeDependencies.Add(
                "$(TargetOutputDir)/System.Runtime.CompilerServices.Unsafe.dll",
                Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Runtime.CompilerServices.Unsafe.dll"));                                                 
            if (Target.bBuildEditor)
            {
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "DevToDev.Analytics.Unreal.Windows.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "DevToDev.Analytics.Unreal.Windows.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "DevToDev.Analytics.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "DevToDev.Analytics.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "DevToDev.Core.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "DevToDev.Core.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "Newtonsoft.Json.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "Newtonsoft.Json.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Data.SQLite.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "System.Data.SQLite.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "SQLite.Interop.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "SQLite.Interop.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "libzstd.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "libzstd.dll"));     
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "ZstdNet.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "ZstdNet.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Buffers.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "System.Buffers.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Memory.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "System.Memory.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Numerics.Vectors.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "System.Numerics.Vectors.dll"));
                CopyFile(
                    Path.Combine(PluginDirectory, "ThirdParty/Windows", architecture, "System.Runtime.CompilerServices.Unsafe.dll"),
                    Path.Combine(PluginDirectory, "Binaries", architecture, "System.Runtime.CompilerServices.Unsafe.dll"));
                                                                           
            }
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            // Add SDK lib include folder to private include paths.
            var includeFolder = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/Mac/include"));
            System.Console.WriteLine("SDK include folder path: " + includeFolder);
            PrivateIncludePaths.Add(includeFolder);

            // Add SDK lib path to dependencies.
            var libPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/Mac/libDTDAnalytics.dylib"));
            System.Console.WriteLine("SDK library file path: " + libPath);
            UnblockOSXFile(libPath);
            PublicAdditionalLibraries.Add(libPath);

            // Add SDK library as runtime dependency to be copied on build.
            RuntimeDependencies.Add("$(BinaryOutputDir)/libDTDAnalytics.dylib", "$(PluginDir)/ThirdParty/Mac/libDTDAnalytics.dylib");
        }
    }

    private static void CopyFile(string source, string dest)
    {
        try
        {
            UnblockWindowsFile(source);
            System.Console.WriteLine("Copying {0} to {1}", source, dest);
            var targetDirectory = Path.GetDirectoryName(dest);
            System.IO.Directory.CreateDirectory(targetDirectory);
            System.IO.File.Copy(source, dest, true);
            Console.WriteLine("OK");
        }
        catch (System.Exception ex)
        {
            System.Console.WriteLine("Failed to copy file: {0}", ex.Message);
        }
    }

    static void UnblockOSXFile(string path)
    {
        try
        {
            Console.WriteLine("Unblocking file: {0}", path);
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "/bin/bash";
            startInfo.Arguments = string.Format("-c \"xattr -r -d com.apple.quarantine '{0}'\"", path);
            startInfo.CreateNoWindow = true;
            startInfo.UseShellExecute = false;
            startInfo.RedirectStandardOutput = true;
            startInfo.RedirectStandardError = true;
            Process process = new Process();
            process.StartInfo = startInfo;
            process.Start();
            process.WaitForExit();
            string error = process.StandardError.ReadToEnd();
            if (string.IsNullOrEmpty(error))
            {
                Console.WriteLine("OK");
            }
            else
            {
                Console.WriteLine("Error: {0}", error);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("Exception: {0}", ex.Message);
        }
    }

    private static void UnblockWindowsFile(string path)
    {
        try
        {
            Console.WriteLine("Unblocking file: {0}", path);
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "powershell.exe";
            startInfo.Arguments = string.Format("Unblock-File -Path '{0}'", path);
            startInfo.CreateNoWindow = true;
            startInfo.UseShellExecute = false;
            startInfo.RedirectStandardOutput = true;
            startInfo.RedirectStandardError = true;
            Process process = new Process();
            process.StartInfo = startInfo;
            process.Start();
            process.WaitForExit();
            string error = process.StandardError.ReadToEnd();
            if (string.IsNullOrEmpty(error))
            {
                Console.WriteLine("OK");
            }
            else
            {
                Console.WriteLine("Error: {0}", error);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("Exception: {0}", ex.Message);
        }
    }
}
