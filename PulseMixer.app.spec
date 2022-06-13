%define prefix /usr/local

Summary: dockable mixer for PulseAudio and Window Maker
Name: PulseMixer.app
Version: 0.1
Release: 1
Source0: %{name}-%{version}.tar.gz
License: GPL
Group: X11/Utilities
BuildRoot: %{_tmppath}/%{name}-root
Packager: Thinksilicon <git@thinksilicon.de>
Requires: XFree86-devel, libXpm-devel, libpulse-devel
URL: https://github/thinksilicon/PulseMixer.App

%description
PulseMixer.app is simple dockable mixer application for WindowMaker. It can
control up to three volume sources, load/store mixer settings, run external
application on middle click (i.e. more sophisticated mixer)

%prep
%setup -q

%build
make

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p -m 0755 $RPM_BUILD_ROOT%{prefix}/bin
cp -f PulseMixer.app $RPM_BUILD_ROOT%{prefix}/bin


%clean
if [ -d $RPM_BUILD_ROOT ]; then rm -rf $RPM_BUILD_ROOT; fi
if [ -d $RPM_BUILD_DIR/%{name}-%{version} ]; then rm -rf $RPM_BUILD_DIR/%{name}-%{version}; fi

%files
%defattr(-,root,root)
%attr(0755,root,root) %{prefix}/bin/PulseMixer.app

%changelog
* Fri Jun 10 2022 Thinksilicon
- forked AlsaMixer.App from Petr and switched over to PulseAudio
- Thanks to falconind for inspiration in ponymix
* Tue Sep 30 2004 Petr Hlavka
- initial release
