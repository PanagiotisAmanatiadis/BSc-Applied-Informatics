import { useEffect, useState } from "react";
import 'bootstrap/dist/css/bootstrap.css'; 
import './App.css';
import web3 from './web3';
import car from './images/car.png';
import laptop from './images/laptop.png';
import phone from './images/phone.png';
import lottery from './lottery';
function App() {

  const [account, setAccount] = useState();
  const [owner, setOwner] = useState();
	const [owner2, setOwner2] = useState();
  const [contractBalance, setContractBalance] = useState();
  const [itemsWon, setItemsWon] = useState();
  const [carTokens, setCarTokens] = useState();
	const [phoneTokens, setPhoneTokens] = useState();
	const [computerTokens, setComputerTokens] = useState();

  useEffect(() => {
		async function getContractOwners() {
			const owner = await lottery.methods.owner().call();
			setOwner(owner);
			const owner2 = await lottery.methods.coOwner().call();
			setOwner2(owner2);
		}
		getContractOwners();
	}, [owner, owner2]);


  async function getAccount() {
		await web3.eth.getAccounts().then((accounts) => {
			setAccount(accounts[0]);
		});
		window.ethereum.on("accountsChanged", (accounts) =>
			setAccount(accounts[0])
		);
	}

  async function getContractBalance() {
		await web3.eth.getBalance(lottery.options.address).then((balance) => {
			setContractBalance(web3.utils.fromWei(balance, "ether"));
		});
	}

  useEffect(() => {
    getAccount();
    getContractBalance();
  }, [account])

  const handleBid = async (id) => {
		// Call the bid function in the contract with id 0, and try to send 0.01 ether
		await lottery.methods
			.bid(id)
			.send({
				from: account,
				value: web3.utils.toWei("0.01", "ether"),
			})
			.then(() => {
				alert("Bid placed to item " + (id));
			})
			.catch((err) => {
				alert("Transaction failed with error: " + err.message);
			});

	};

  const handleReveal = async () => {
		// Call the getNumTokens function in the contract
		await lottery.methods
			.getNumberOfTokens()
			.call()
			.then((numTokens) => {
				// Get the number of tokens for each item
				setCarTokens(numTokens[0]);
				setPhoneTokens(numTokens[1]);
				setComputerTokens(numTokens[2]);
			});
		// Get the contract balance
		getContractBalance();
	};

  const handleWithdraw = async () => {
		// Call the withdraw function in the contract
		await lottery.methods
			.withdraw()
			.send({
				from: account,
			})
			.then(() => {
				alert("Successfully withdrew " + contractBalance + " ether");
				// Get the contract balance
				getContractBalance();
			})
			.catch((err) => {
				alert("Transaction failed with error: " + err.message);
			});
	};

  const handleRevealWinners = async () => {
		// Call the revealWinners function in the contract
		await lottery.methods
			.revealWinners()
			.send({
				from: account,
			})
			.then(() => {
				alert("Winners revealed");
			})
			.catch((err) => {
				alert("Transaction failed with error: " + err.message);
			});
	};

  const handleAmIWinner = async () => {
		// Call getItemsWon function in the contract
		await lottery.methods
			.getItemsWon()
			.call({
				from: account,
			})
			.then((itemsWon) => {
				// if the items won are not empty, set the items won to the items won
				if (itemsWon.length > 0) {
					setItemsWon(itemsWon);
				}
				// if the items won are empty, set the items won to the empty array
				else {
					setItemsWon([]);
				}
			})
			.catch((err) => {
				alert("Transaction failed with error: " + err.message);
				setItemsWon();
			});
	};

  const handleReset = async() => {
    await lottery.methods
      .reset().send({from:account,}).then(()=>{alert("reset done");}).catch((err) =>{alert(err.message);});
  };

  return (
    <div className="App d-flex flex-column p-5 container-xl">
      <header className="border-bottom">
       <h1>Lottery - Ballot</h1>
      </header>

      <div className="d-flex mt-5 gap-3">
        

        <div className="card col ">
          <div className="card-header">
            <h3>
              Car
            </h3>
          </div>
          <div className="card-body d-flex flex-column">
            <img src={car} alt="Car" className="img-fluid"/>
            <div className="d-flex justify-content-between mt-auto">
            <button className="btn btn-outline-secondary right-aline" onClick={()=>handleBid(0)}>Bid</button>
            <h3>{carTokens}</h3>
            </div>
          </div>
        </div>


        <div className="card col ">
          <div className="card-header">
            <h3>
              Phone
            </h3>
          </div>
          <div className="card-body d-flex flex-column">
            <img src={phone} alt="Car" className="img-fluid"/>
            <div className="d-flex justify-content-between mt-auto">
            <button className="btn  btn-outline-secondary right-aline" onClick={()=>handleBid(1)}>Bid</button>
            <h3>{phoneTokens}</h3>
            </div>
          </div>
        </div>


        <div className="card col ">
          <div className="card-header">
            <h3>
              Laptop
            </h3>
          </div>
          <div className="card-body d-flex flex-column">
            <img src={laptop} alt="Car" className="img-fluid"/>
            <div className="d-flex justify-content-between mt-auto">
            <button className="btn  btn-outline-secondary right-aline" onClick={()=>handleBid(2)}>Bid</button>
            <h3>{computerTokens}</h3>
            </div>
          </div>
        </div>



      </div>
      
      <div className="d-flex flex-wrap justify-content-between mt-4 gap-5">
      
        <div className="d-flex flex-column flex-wrap gap-2">
          <span className="me-auto">Current Account:</span>
					<span className="mb-4 border border-1 border-dark rounded px-2">
						{account}

          </span>
          <div className="d-flex flex-column gap-2">
            <button className="w-50 btn btn-primary text-light me-auto" onClick={handleReveal}>Reveal</button>
            <button className="w-50 btn btn-primary text-light me-auto" onClick={handleAmIWinner}>Am I Winner</button>
            {
              itemsWon && itemsWon.length>0?(
                <span className="me-auto">
                  Items Won: {itemsWon.toString()}
                </span>
              ):(
                itemsWon && (
                  <span className="me-auto">
                    Items Won:You have won 0 items.
                  </span>
                )
              )
            }
          </div>

          

        </div>  

        <div className="d-flex flex-column flex-wrap gap-2">
          <span className="me-auto">Owner's Account:</span>
					<span className="mb-4 border border-1 border-dark rounded px-2">
						{owner}

          </span>
          <div className="d-flex flex-column gap-2">
            <button className="w-50 btn btn-success text-light ms-auto" onClick={handleWithdraw}>Withdraw</button>
            <button className="w-50 btn btn-success text-light ms-auto" onClick={handleRevealWinners}>Declare Winner</button>
            <button className="w-50 btn btn-success text-light ms-auto" onClick={handleReset}>Reset</button>
          </div>
          
        </div>




      </div>




    <span>
      Contract Balance {contractBalance} ether
    </span>

    
    </div>
  );
}

export default App;
