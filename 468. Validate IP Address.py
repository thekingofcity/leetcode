class Solution:
    def validIPAddress(self, IP: str) -> str:
        elems = IP.split('.')

        if len(elems) == 4:
            for elem in elems:
                if (not elem) or (not elem.isdigit()):
                    return "Neither"
                if elem[0] == '0' and len(elem) > 1:
                    return "Neither"
                elem = int(elem)
                if elem < 0 or elem > 255:
                    return "Neither"
            return "IPv4"

        elems = IP.split(':')
        if len(elems) == 8:
            for elem in elems:
                if (not elem) or len(elem) < 1 or len(elem) > 4:
                    return "Neither"
                try:
                    elem = int(elem, 16)
                except Exception:
                    return "Neither"
            return "IPv6"

        return "Neither"
