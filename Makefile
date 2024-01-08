default: build
ios: build ent

build:
	clang -Os tfpn.c -o tfpn

ent:
	ldid -Sent.plist tfpn

clean:
	rm -f tfpn