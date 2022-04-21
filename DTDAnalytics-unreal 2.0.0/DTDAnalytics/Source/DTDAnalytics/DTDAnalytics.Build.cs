// Copyright (c) devtodev. All rights reserved.

using System;
using System.IO;
using System.Diagnostics;
using UnrealBuildTool;

public class DTDAnalytics : ModuleRules
{
    public DTDAnalytics(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.Add("Core");

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
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            var frameworkPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/iOS/DTDAnalytics.framework.zip"));
            PublicAdditionalFrameworks.Add(new Framework("DTDAnalytics", frameworkPath));
            var pluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(pluginPath, "DTDAnalytics_UPL_iOS.xml"));
            PublicFrameworks.AddRange(new string[]
            {
                "AdSupport",
                "StoreKit",
                "UserNotifications"
            });
            PublicWeakFrameworks.AddRange(new string[] 
            {
                "AppTrackingTransparency"
            });
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
