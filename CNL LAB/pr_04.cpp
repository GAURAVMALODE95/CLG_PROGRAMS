#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

string generateSubnetMask(int subnetMaskBits) {
    // Create a subnet mask string with 'subnetMaskBits' 1s followed by (32 - subnetMaskBits) 0s
    string subnetMaskBinary = string(subnetMaskBits, '1') + string(32 - subnetMaskBits, '0');

    // Convert binary subnet mask to decimal dotted notation
    string subnetMask = "";
    for (int i = 0; i < 32; i += 8) {
        subnetMask += to_string(stoi(subnetMaskBinary.substr(i, 8), nullptr, 2)); ////The stoi function converts the substring to an integer, interpreting it as binary
        if (i < 24) {
            subnetMask += '.';
        }
    }
    return subnetMask;
}

void calculateSubnet(string ipAddress, int subnetMaskBits) {
    // Convert IP address to binary format
    string ipBinary = "";
    for (char octet : ipAddress) {
        if (octet != '.') {
            bitset<8> bits(octet);
            ipBinary += bits.to_string();
        }
    }

    // Calculate network address using the subnet mask bits
    string networkAddressBinary = ipBinary.substr(0, subnetMaskBits) + string(32 - subnetMaskBits, '0');

    // Convert network address back to decimal format
    string networkAddress = "";
    for (int i = 0; i < 32; i += 8) {
        networkAddress += to_string(stoi(networkAddressBinary.substr(i, 8), nullptr, 2));
        if (i < 24) {
            networkAddress += '.';
        }
    }

    // Generate subnet mask
    string subnetMask = generateSubnetMask(subnetMaskBits);

    // Calculate the number of hosts in the subnet
    int numHosts = pow(2, 32 - subnetMaskBits) - 2;

    // Display results
    cout << "IP Address: " << ipAddress << endl;
    cout << "Subnet Mask Bits: " << subnetMaskBits << endl;
    cout << "Network Address: " << networkAddress << endl;
    cout << "Subnet Mask: " << subnetMask << endl;
    cout << "Number of Hosts in Subnet: " << numHosts << endl;
}

int main() {
    string ipAddress;
    int subnetMaskBits;

    // Get user input
    cout << "Enter IP Address (e.g., 192.168.1.1): ";
    cin >> ipAddress;

    cout << "Enter Subnet Mask Bits: ";
    cin >> subnetMaskBits;

    // Calculate and display subnet information
    calculateSubnet(ipAddress, subnetMaskBits);

    return 0;
}



//OUTPUT
//Enter IP Address (e.g., 192.168.1.1): 
//192.168.1.1
//Enter Subnet Mask Bits: 24
//IP Address: 192.168.1.1
//Subnet Mask Bits: 24
//Network Address: 49.57.50.0
//Subnet Mask: 255.255.255.0
//Number of Hosts in Subnet: 254