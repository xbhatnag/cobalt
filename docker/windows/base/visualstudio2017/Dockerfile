# escape=`

# Copyright 2021 The Cobalt Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
ARG FROM_IMAGE
FROM ${FROM_IMAGE}

# Dockerfile for image used to install Visual Studio.
# WARNING: Changes to this file will result in an extremely long image rebuild.

SHELL ["powershell", "-ExecutionPolicy", "unrestricted", "-Command"]

RUN mkdir C:\TEMP;`
    Write-Host ('Downloading vs_buildtools.exe');`
    Invoke-WebRequest -Uri https://aka.ms/vs/15/release/vs_buildtools.exe -OutFile C:\TEMP\vs_buildtools.exe;`
    Write-Host ('Installing vs_buildtools.exe');`
    Start-Process C:\TEMP\vs_buildtools.exe -Wait -NoNewWindow`
        -ArgumentList '--quiet --wait --norestart --nocache`
        --installPath C:\BuildTools `
        --add Microsoft.VisualStudio.Component.VC.CoreIde `
        --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
        --add Microsoft.VisualStudio.Component.Windows10SDK.17763 `
        --add Microsoft.VisualStudio.Component.VC.Tools.14.15';`
    Write-Host ('Cleaning up vs_buildtools.exe');`
    Remove-Item -Force -Recurse ${env:ProgramFiles(x86)}\'Microsoft Visual Studio'\Installer;`
    Remove-Item -Force -Recurse $env:TEMP\*;`
    Remove-Item -Force -Recurse $env:ProgramData\'Package Cache'\;`
    Remove-Item -Force -Recurse C:\BuildTools\Common7\IDE\CommonExtensions\Microsoft\TextMate\Starterkit\Extensions;`
    Remove-Item -Force -Recurse C:\BuildTools\VC\Tools\MSVC\14.15.26726\atlmfc;`
    Remove-Item -Force -Recurse C:\BuildTools\VC\Tools\MSVC\14.15.26726\lib\spectre;`
    Remove-Item C:\TEMP\vs_buildtools.exe

ENV VSINSTALLDIR "C:\BuildTools"
ENV MSVC_TOOLS_VERSION "14.16.27023"
ENV MSVC_REDIST_VERSION "14.16.27012"

# TODO: remove this environment variable setting, since it is only needed for
# manually deploying debug versions of DLLs. This can be removed in favor of a
# dedicated deployment through gyp/ninja.
ENV MS_WIN_VERSION="10.0.17763.0"
