import Web3 from 'web3';
async function getWeb3(){await window.ethereum.request({ method: "eth_requestAccounts" });}
getWeb3();
const web3=new Web3(window.ethereum);
export default web3;