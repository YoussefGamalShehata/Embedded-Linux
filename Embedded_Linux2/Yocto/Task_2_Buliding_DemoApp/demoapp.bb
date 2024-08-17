#Header Section
SUMMARY="This recipe should clone a DemoApp CALCULATOR Package"
DESCRIPTION = "Calculator Application Package needed to be as a part of the final image so we have to create a recipe that processes the application."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

#Development Section

SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"
SRCREV="720c663c5fd7246b4b42c5205d74db7d9784b5b2"

inherit cmake

do_configure() {
    #staticlly build
    cmake -S ${WORKDIR}/git -B ${B} -DCMAKE_EXE_LINKER_FLAGS="-static" -DCMAKE_SHARED_LINKER_FLAGS="-static"
}

do_compile() {
    cd ${B}
    oe_runmake || die "make failed"
}

do_install() {
    mkdir -p ${D}${bindir}
    cp ${B}/calculator ${D}${bindir}
}